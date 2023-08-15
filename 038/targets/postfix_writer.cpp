#include <string>
#include <sstream>
#include "targets/type_checker.h"
#include "targets/postfix_writer.h"
#include <stack>
#include ".auto/all_nodes.h"  // all_nodes.h is automatically generated

std::shared_ptr<mml::symbol> _function; // for keeping track of the current function and its arguments
bool _errors, _inFunction, _inFunctionName, _inFunctionArgs, _inFunctionBody;
bool _returnSeen; // when building a function
std::stack<int> _whileTest, _whileEnd; //for again/stop
std::stack<bool> _globals; // for deciding whether a variable is global or not
std::stack<int> _functionsLabels;
int _offset; // current framepointer offset (0 means no vars defined)
cdk::typename_type _lvalueType;

// remember function name for resolving '@'
std::string _currentFunctionName;
std::string _currentBodyRetLabel; // where to jump when a return occurs of an exclusive section ends
//---------------------------------------------------------------------------

void mml::postfix_writer::do_nil_node(cdk::nil_node * const node, int lvl) {
  // EMPTY
}
void mml::postfix_writer::do_data_node(cdk::data_node * const node, int lvl) {
  // EMPTY
}
void mml::postfix_writer::do_double_node(cdk::double_node * const node, int lvl) {
  if (_inFunctionBody) {
    _pf.DOUBLE(node->value()); // load number to the stack
  } else {
    _pf.SDOUBLE(node->value());    // double is on the DATA segment
  }
}

void mml::postfix_writer::do_not_node(cdk::not_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1, lbl2;
  node->argument()->accept(this, lvl); // determine the value
  _pf.INT(0);
  _pf.EQ();
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  _pf.INT(1);
  _pf.JMP(mklbl(lbl2 = ++_lbl));
  _pf.LABEL(mklbl(lbl1));
  _pf.INT(0);
  _pf.LABEL(mklbl(lbl2));
}

void mml::postfix_writer::do_and_node(cdk::and_node * const node, int lvl) {
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JZ(mklbl(lbl));
  _pf.TRASH(4);
  node->right()->accept(this, lvl + 2);
  _pf.AND();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

void mml::postfix_writer::do_or_node(cdk::or_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl = ++_lbl;
  node->left()->accept(this, lvl + 2);
  _pf.DUP32();
  _pf.JNZ(mklbl(lbl));
  node->right()->accept(this, lvl + 2);
  _pf.OR();
  _pf.ALIGN();
  _pf.LABEL(mklbl(lbl));
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_sequence_node(cdk::sequence_node * const node, int lvl) {
  for (size_t i = 0; i < node->size(); i++) {
    node->node(i)->accept(this, lvl);
  }
}

// ============================================================
//    3.8 - Literais
// ============================================================

void mml::postfix_writer::do_integer_node(cdk::integer_node * const node, int lvl) {
 if (_inFunctionBody) {
    _pf.INT(node->value()); // integer literal is on the stack: push an integer
  } else {
    _pf.SINT(node->value()); // integer literal is on the DATA segment
  }
}

void mml::postfix_writer::do_string_node(cdk::string_node * const node, int lvl) {
  int lbl1;

  /* generate the string */
  _pf.RODATA(); // strings are DATA readonly
  _pf.ALIGN(); // make sure we are aligned
  _pf.LABEL(mklbl(lbl1 = ++_lbl)); // give the string a name
  _pf.SSTRING(node->value()); // output string characters

  /* leave the address on the stack */
  _pf.TEXT(); // return to the TEXT segment
  _pf.ADDR(mklbl(lbl1)); // the string to be printed
}

void mml::postfix_writer::do_null_pointer_node(mml::null_pointer_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  if (_inFunctionBody) {
    _pf.INT(0);
  } else {
    _pf.SINT(0);
  }
}

// === 3.8 - END ================================================

void mml::postfix_writer::do_neg_node(cdk::neg_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
   if (node->is_typed(cdk::TYPE_INT)) {
    _pf.NEG(); // 2-complement
  }
  else if (node->is_typed(cdk::TYPE_DOUBLE)) {
    _pf.DNEG();  //negate floating point
  }
  else {
    throw std::string("Error: Cannot happen!");
  }
}



//---------------------------------------------------------------------------

void mml::postfix_writer::do_add_node(cdk::add_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.ADD();
}
void mml::postfix_writer::do_sub_node(cdk::sub_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.SUB();
}
void mml::postfix_writer::do_mul_node(cdk::mul_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MUL();
}
void mml::postfix_writer::do_div_node(cdk::div_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.DIV();
}
void mml::postfix_writer::do_mod_node(cdk::mod_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.MOD();
}
void mml::postfix_writer::do_lt_node(cdk::lt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LT();
}
void mml::postfix_writer::do_le_node(cdk::le_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.LE();
}
void mml::postfix_writer::do_ge_node(cdk::ge_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GE();
}
void mml::postfix_writer::do_gt_node(cdk::gt_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.GT();
}
void mml::postfix_writer::do_ne_node(cdk::ne_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.NE();
}
void mml::postfix_writer::do_eq_node(cdk::eq_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->left()->accept(this, lvl);
  node->right()->accept(this, lvl);
  _pf.EQ();
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_variable_node(cdk::variable_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  // simplified generation: all variables are global
  _pf.ADDR(node->name());
}

void mml::postfix_writer::do_rvalue_node(cdk::rvalue_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
  _pf.LDINT(); // depends on type size
}

void mml::postfix_writer::do_assignment_node(cdk::assignment_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->rvalue()->accept(this, lvl); // determine the new value
  _pf.DUP32();
  if (new_symbol() == nullptr) {
    node->lvalue()->accept(this, lvl); // where to store the value
  } else {
    _pf.DATA(); // variables are all global and live in DATA
    _pf.ALIGN(); // make sure we are aligned
    _pf.LABEL(new_symbol()->name()); // name variable location
    reset_new_symbol();
    _pf.SINT(0); // initialize it to 0 (zero)
    _pf.TEXT(); // return to the TEXT segment
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }
  _pf.STINT(); // store the value at address
}


// ============================================================
//    4 - Gramática
// ============================================================

void mml::postfix_writer::do_variable_declaration_node(mml::variable_declaration_node * const node, int lvl) {
  // TODO
}


// ============================================================
//    5 - Funções
// ============================================================

void mml::postfix_writer::do_function_definition_node(mml::function_definition_node *const node, int lvl) {
  // TODO
}

void mml::postfix_writer::do_function_call_node(mml::function_call_node * const node, int lvl) {
  // TODO
}

void mml::postfix_writer::do_block_node(mml::block_node * const node, int lvl) {
  // TODO
  //REVIEW
  _symtab.push(); 
  if (node->declaration()) node->declaration()->accept(this, lvl + 2);
  if (node->instruction()) node->instruction()->accept(this, lvl + 2);
  _symtab.pop();
}

void mml::postfix_writer::do_program_node(mml::program_node * const node, int lvl) {
  // Note that MML doesn't have functions. Thus, it doesn't need
  // a function node. However, it must start in the main function.
  // The ProgramNode (representing the whole program) doubles as a
  // main function node.

  // generate the main function (RTS mandates that its name be "_main")
  _pf.TEXT();
  _pf.ALIGN();
  _pf.GLOBAL("_main", _pf.FUNC());
  _pf.LABEL("_main");
  _pf.ENTER(0);  // MML doesn't implement local variables

  node->statements()->accept(this, lvl);

  // end the main function
  _pf.INT(0);
  _pf.STFVAL32();
  _pf.LEAVE();
  _pf.RET();

  // these are just a few library function imports
  _pf.EXTERN("readi");
  _pf.EXTERN("printi");
  _pf.EXTERN("prints");
  _pf.EXTERN("println");
}


// ============================================================
//    6 - Instruções
// ============================================================ 


// ============================================================
//    7.1 - Expressões primitivas
// ============================================================

void mml::postfix_writer::do_input_node(mml::input_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  if (_lvalueType == cdk::TYPE_DOUBLE) {
    _functions_to_declare.insert("readd");
    _pf.CALL("readd");
    _pf.LDFVAL64();
  } else if (_lvalueType == cdk::TYPE_INT) {
    _functions_to_declare.insert("readi");
    _pf.CALL("readi");
    _pf.LDFVAL32();
  } else {
    std::cerr << "FATAL: " << node->lineno() << ": cannot read type" << std::endl;
    return;
  }
}


// ============================================================
//    7.2 - Expressões resultantes de avaliação de operadores
// ============================================================

void mml::postfix_writer::do_index_node(mml::index_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  if (node->base()) {
    node->base()->accept(this, lvl);
  } else {
    if (_function) {
      _pf.LOCV(-_function->type()->size());
    } else {
      std::cerr << "FATAL: " << node->lineno() << ": trying to use return value outside function" << std::endl;
    }
  }
  node->index()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ADD(); // add pointer and index
}

void mml::postfix_writer::do_identity_node(mml::identity_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
}

void mml::postfix_writer::do_stack_alloc_node(mml::stack_alloc_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl);
  _pf.INT(3);
  _pf.SHTL();
  _pf.ALLOC(); // allocate
  _pf.SP(); // put base pointer in stack

}

void mml::postfix_writer::do_address_of_node(mml::address_of_node *const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  node->lvalue()->accept(this, lvl);
}

void mml::postfix_writer::do_sizeof_node(mml::sizeof_node *const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  _pf.INT(node->expression()->type()->size());
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_if_node(mml::if_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  int lbl1;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl1 = ++_lbl));
  node->block()->accept(this, lvl + 2);
  _pf.LABEL(mklbl(lbl1));
}


//---------------------------------------------------------------------------

void mml::postfix_writer::do_if_else_node(mml::if_else_node * const node, int lvl) {
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  int lbl_else, lbl_end;
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(lbl_else = lbl_end = ++_lbl));
  node->thenblock()->accept(this, lvl + 2);
  if (node->elseblock()) {
    _pf.JMP(mklbl(lbl_end = ++_lbl));
    _pf.LABEL(mklbl(lbl_else));
    node->elseblock()->accept(this, lvl + 2);
  }
  _pf.LABEL(mklbl(lbl_end));
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_while_node(mml::while_node * const node, int lvl) {
  //REVIEW
  ASSERT_SAFE_EXPRESSIONS;
  
  _forStep.push(++_lbl); 
  _forEnd.push(++_lbl);

  //int lbl1, lbl2;
  _pf.LABEL(mklbl(_forStep.top()));
  node->condition()->accept(this, lvl);
  _pf.JZ(mklbl(_forEnd.top()));
  node->block()->accept(this, lvl + 2);
  _pf.JMP(mklbl(_forStep.top()));
  _pf.LABEL(mklbl(_forEnd.top()));

  _forStep.pop();
  _forEnd.pop();
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_stop_node(mml::stop_node * const node, int lvl) {
  // TODO
  //REVIEW
  if (_forEnd.size() != 0) {
    _pf.JMP(mklbl(_forEnd.top()));
  } else
    error(node->lineno(), "'next' outside 'while'");
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_next_node(mml::next_node * const node, int lvl) {
  // TODO
  //REVIEW
  if (_forStep.size() != 0) {
    _pf.JMP(mklbl(_forStep.top())); 
  } else
    error(node->lineno(), "'stop' outside 'for'");
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_return_node(mml::return_node *const node, int lvl){
  ASSERT_SAFE_EXPRESSIONS;
  // should not reach here without returning a value (if not void)
  if(_function->is_main()){
    node->value()->accept(this, lvl + 2);
    _pf.JMP(_currentBodyRetLabel);
    _returnSeen = true;
    return;
  }

  if (_function->type()->name() != cdk::TYPE_VOID) {
    node->value()->accept(this, lvl + 2);

    if (_function->type()->name() == cdk::TYPE_INT || _function->type()->name() == cdk::TYPE_STRING
        || _function->type()->name() == cdk::TYPE_POINTER) {
      _pf.STFVAL32();
    } else if (_function->type()->name() == cdk::TYPE_DOUBLE) {
      if (node->value()->type()->name() == cdk::TYPE_INT) _pf.I2D();
      _pf.STFVAL64();
    } else {
      std::cerr << node->lineno() << ": should not happen: unknown return type" << std::endl;
    }
  }

  _pf.JMP(_currentBodyRetLabel);
  _returnSeen = true;
}

//---------------------------------------------------------------------------

void mml::postfix_writer::do_print_node(mml::print_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->sequence()->accept(this, lvl); // determine the value to print
  
  /*
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    _pf.CALL("printi");
    _pf.TRASH(4); // delete the printed value
  } else if (node->argument()->is_typed(cdk::TYPE_STRING)) {
    _pf.CALL("prints");
    _pf.TRASH(4); // delete the printed value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
  */
  if (node->is_println()) {
    _pf.CALL("println"); // print a newline
  }
}

void mml::postfix_writer::do_evaluation_node(mml::evaluation_node * const node, int lvl) {
  ASSERT_SAFE_EXPRESSIONS;
  node->argument()->accept(this, lvl); // determine the value
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    _pf.TRASH(4); // delete the evaluated value
  } else if (node->argument()->is_typed(cdk::TYPE_STRING)) {
    _pf.TRASH(4); // delete the evaluated value's address
  } else {
    std::cerr << "ERROR: CANNOT HAPPEN!" << std::endl;
    exit(1);
  }
}