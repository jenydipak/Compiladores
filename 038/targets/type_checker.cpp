#include <string>
#include "targets/type_checker.h"
#include ".auto/all_nodes.h"  // automatically generated
#include <cdk/types/primitive_type.h>
//#include "targets/symbol.h"

#define ASSERT_UNSPEC { if (node->type() != nullptr && !node->is_typed(cdk::TYPE_UNSPEC)) return; }

//---------------------------------------------------------------------------

void mml::type_checker::do_sequence_node(cdk::sequence_node *const node, int lvl) {
  // EMPTY
  //REVIEW
  for (size_t i=0; i<node->size(); i++)
    node->node(i)->accept(this,lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_nil_node(cdk::nil_node *const node, int lvl) {
  // EMPTY
}
void mml::type_checker::do_data_node(cdk::data_node *const node, int lvl) {
  // EMPTY
}
void mml::type_checker::do_double_node(cdk::double_node *const node, int lvl) {
  // EMPTY
  //REVIEW
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(8, cdk::TYPE_DOUBLE));
}
void mml::type_checker::do_not_node(cdk::not_node *const node, int lvl) {
  // EMPTY
  //REVIEW
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (node->argument()->is_typed(cdk::TYPE_INT)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else if (node->argument()->is_typed(cdk::TYPE_UNSPEC)) {
    node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
    node->argument()->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
  } else {
    throw std::string("wrong type in unary logical expression");
  }
}
void mml::type_checker::do_and_node(cdk::and_node *const node, int lvl) {
  // EMPTY
  //REVIEW
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_or_node(cdk::or_node *const node, int lvl) {
  // EMPTY
  //REVIEW
  processBinaryExpression(node, lvl);
}

// ============================================================
//    3.8 - Literais
// ============================================================

void mml::type_checker::do_integer_node(cdk::integer_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_string_node(cdk::string_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->type(cdk::primitive_type::create(4, cdk::TYPE_STRING));
}

void mml::type_checker::do_null_pointer_node(mml::null_pointer_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_UNSPEC;
  node->type(cdk::reference_type::create(4, nullptr));
}

// === 3.8 - END ================================================

void mml::type_checker::processUnaryExpression(cdk::unary_operation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT) && !node->argument()->is_typed(cdk::TYPE_DOUBLE)) throw std::string("wrong type in argument of unary expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_neg_node(cdk::neg_node *const node, int lvl) {
  processUnaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::processBinaryExpression(cdk::binary_operation_node *const node, int lvl) {
  ASSERT_UNSPEC;
  node->left()->accept(this, lvl + 2);
  if (!node->left()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in left argument of binary expression");

  node->right()->accept(this, lvl + 2);
  if (!node->right()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in right argument of binary expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}

void mml::type_checker::do_add_node(cdk::add_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_sub_node(cdk::sub_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_mul_node(cdk::mul_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_div_node(cdk::div_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_mod_node(cdk::mod_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_lt_node(cdk::lt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_le_node(cdk::le_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_ge_node(cdk::ge_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_gt_node(cdk::gt_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_ne_node(cdk::ne_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}
void mml::type_checker::do_eq_node(cdk::eq_node *const node, int lvl) {
  processBinaryExpression(node, lvl);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_variable_node(cdk::variable_node *const node, int lvl) {
  ASSERT_UNSPEC;
  const std::string &id = node->name();
  std::shared_ptr<mml::symbol> symbol = _symtab.find(id);

  if (symbol != nullptr) {
    node->type(symbol->type());
  } else {
    throw id;
  }
}

void mml::type_checker::do_rvalue_node(cdk::rvalue_node *const node, int lvl) {
  ASSERT_UNSPEC;
  try {
    node->lvalue()->accept(this, lvl);
    node->type(node->lvalue()->type());
  } catch (const std::string &id) {
    throw "undeclared variable '" + id + "'";
  }
}

void mml::type_checker::do_assignment_node(cdk::assignment_node *const node, int lvl) {
  ASSERT_UNSPEC;

  try {
    node->lvalue()->accept(this, lvl);
  } catch (const std::string &id) {
    auto symbol = std::make_shared<mml::symbol>(cdk::primitive_type::create(4, cdk::TYPE_INT), id, 0);
    _symtab.insert(id, symbol);
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
    node->lvalue()->accept(this, lvl);  //DAVID: bah!
  }

  if (!node->lvalue()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in left argument of assignment expression");

  node->rvalue()->accept(this, lvl + 2);
  if (!node->rvalue()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type in right argument of assignment expression");

  // in MML, expressions are always int
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}


// ============================================================
//    4 - Gramática
// ============================================================

void mml::type_checker::do_variable_declaration_node(mml::variable_declaration_node * const node, int lvl) {
  // TODO
  //REVIEW
  if (node->initializer() != nullptr) {
    node->initializer()->accept(this, lvl + 2);

    if (node->is_typed(cdk::TYPE_INT)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (node->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->initializer()->is_typed(cdk::TYPE_INT) && !node->initializer()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (node->is_typed(cdk::TYPE_STRING)) {
      if (!node->initializer()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (node->is_typed(cdk::TYPE_POINTER)) {
      if (!node->initializer()->is_typed(cdk::TYPE_POINTER)) {
        throw std::string("wrong type for initializer (pointer expected).");
      }
    } else {
      throw std::string("unknown type for initializer.");
    }
  }

  const std::string &id = node->identifier();
  auto symbol = mml::make_shared(false, node->qualifier(), node->type(), id, (bool)node->initializer(), false);
  if (_symtab.insert(id, symbol)) {
    _parent->set_new_symbol(symbol);  // advise parent that a symbol has been inserted
  } else {
    throw std::string("variable '" + id + "' redeclared");
  }

}


// ============================================================
//    5 - Funções
// ============================================================

void mml::type_checker::do_function_definition_node(mml::function_definition_node *const node, int lvl) {
  // TODO
  //REVIEW
  std::vector < std::shared_ptr < cdk::basic_type >> argtypes;
  if(node->arguments()){
    node->arguments()->accept(this, lvl + 2);
    
    for (size_t ax = 0; ax < node->arguments()->size(); ax++){
      auto *arg = node->argument(ax);
      argtypes.push_back(arg->type());
    }
  }

  auto Type_return = node->type();
  node->type(cdk::functional_type::create(argtypes, Type_return));

}

void mml::type_checker::do_function_call_node(mml::function_call_node * const node, int lvl) {
  // TODO
}

void mml::type_checker::do_block_node(mml::block_node * const node, int lvl) {
  // TODO
  //REVIEW
  if (node->declaration()){
      node->declaration()->accept(this, lvl + 2);
  }
  if (node->instruction()){
      node->instruction()->accept(this, lvl + 2);
  }
}

void mml::type_checker::do_program_node(mml::program_node *const node, int lvl) {
  // EMPTY
  //NAO SEI SE É SUPOSTO FAZER?
}


// ============================================================
//    6 - Instruções
// ============================================================

void mml::type_checker::do_if_node(mml::if_node *const node, int lvl) {
  //REVIEW
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
  node->block()->accept(this, lvl + 4);
}

void mml::type_checker::do_if_else_node(mml::if_else_node *const node, int lvl) {
  //REVIEW
  node->condition()->accept(this, lvl + 4);
  if (!node->condition()->is_typed(cdk::TYPE_INT)) throw std::string("expected integer condition");
  node->thenblock()->accept(this, lvl + 4);
  node->elseblock()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_while_node(mml::while_node *const node, int lvl) {
  node->condition()->accept(this, lvl + 4);
  node->block()->accept(this, lvl + 4);
}

//---------------------------------------------------------------------------

void mml::type_checker::do_stop_node(mml::stop_node * const node, int lvl) {
  // TODO
  //
}

//---------------------------------------------------------------------------

void mml::type_checker::do_next_node(mml::next_node * const node, int lvl) {
  // TODO
  //REVIEW
}

//---------------------------------------------------------------------------

void mml::type_checker::do_return_node(mml::return_node *const node, int lvl) {
   if (node->value()) {
    if (_function->type() != nullptr && _function->is_typed(cdk::TYPE_VOID)) throw std::string(
        "initializer specified for void function.");

    node->value()->accept(this, lvl + 2);

    // function is avar: copy type of first return expression
    if (_function->type() == nullptr) {
      _function->set_type(node->value()->type());
      return; // simply set the type
    }

    std::cout << "FUNCT TYPE " << (_function->type() == nullptr ? "auto" : cdk::to_string(_function->type())) << std::endl;
    std::cout << "value TYPE " << cdk::to_string(node->value()->type()) << std::endl;

    if (_function->is_typed(cdk::TYPE_INT)) {
      if (!node->value()->is_typed(cdk::TYPE_INT)) throw std::string("wrong type for initializer (integer expected).");
    } else if (_function->is_typed(cdk::TYPE_DOUBLE)) {
      if (!node->value()->is_typed(cdk::TYPE_INT) && !node->value()->is_typed(cdk::TYPE_DOUBLE)) {
        throw std::string("wrong type for initializer (integer or double expected).");
      }
    } else if (_function->is_typed(cdk::TYPE_STRING)) {
      if (!node->value()->is_typed(cdk::TYPE_STRING)) {
        throw std::string("wrong type for initializer (string expected).");
      }
    } else if (_function->is_typed(cdk::TYPE_POINTER)) {
      int ft = 0, rt = 0;
      auto ftype = _function->type();
      while (ftype->name() == cdk::TYPE_POINTER) {
        ft++;
        ftype = cdk::reference_type::cast(ftype)->referenced();
      }
      auto rtype = node->value()->type();
      while (rtype != nullptr && rtype->name() == cdk::TYPE_POINTER) {
        rt++;
        rtype = cdk::reference_type::cast(rtype)->referenced();
      }

      std::cout << "FUNCT TYPE " << cdk::to_string(_function->type()) << " --- " << ft << " -- " << ftype->name() << std::endl;
      std::cout << "value TYPE " << cdk::to_string(node->value()->type()) << " --- " << rt << " -- " << cdk::to_string(rtype)
          << std::endl;

      bool compatible = (ft == rt) && (rtype == nullptr || (rtype != nullptr && ftype->name() == rtype->name()));
      if (!compatible) throw std::string("wrong type for return expression (pointer expected).");

    } else {
      throw std::string("unknown type for initializer.");
    }
  }
}

void mml::type_checker::do_evaluation_node(mml::evaluation_node *const node, int lvl) {
  node->argument()->accept(this, lvl + 2);
}

void mml::type_checker::do_print_node(mml::print_node *const node, int lvl) {
  node->sequence()->accept(this, lvl + 2);
}


// ============================================================
//    7.1 - Expressões primitivas
// ============================================================

void mml::type_checker::do_input_node(mml::input_node *const node, int lvl) {
    // TODO
    //REVIEW
    node->type(cdk::primitive_type::create(0, cdk::TYPE_UNSPEC));
}


// ============================================================
//    7.2 - Expressões resultantes de avaliação de operadores
// ============================================================

void mml::type_checker::do_index_node(mml::index_node * const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_UNSPEC;
  std::shared_ptr < cdk::reference_type > btype;

  if (node->base()) {
    node->base()->accept(this, lvl + 2);
    btype = cdk::reference_type::cast(node->base()->type());
    if (!node->base()->is_typed(cdk::TYPE_POINTER)) throw std::string("pointer expression expected in index left-value");
  } else {
    btype = cdk::reference_type::cast(_function->type());
    if (!_function->is_typed(cdk::TYPE_POINTER)) throw std::string("return pointer expression expected in index left-value");
  }

  node->index()->accept(this, lvl + 2);
  if (!node->index()->is_typed(cdk::TYPE_INT)) throw std::string("integer expression expected in left-value index");

  node->type(btype->referenced());
}

void mml::type_checker::do_identity_node(mml::identity_node * const node, int lvl) {
  // TODO
  //REVIEW
  processUnaryExpression(node, lvl);
}

void mml::type_checker::do_stack_alloc_node(mml::stack_alloc_node *const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_UNSPEC;
  node->argument()->accept(this, lvl + 2);
  if (!node->argument()->is_typed(cdk::TYPE_INT)) {
    throw std::string("Expected integer expression in the allocation expression");
  }
}

void mml::type_checker::do_address_of_node(mml::address_of_node *const node, int lvl) {
  // TODO
  //REVIEW
  ASSERT_UNSPEC;
  node->lvalue()->accept(this, lvl + 2);
  node->type(cdk::reference_type::create(4, node->lvalue()->type()));
}

void mml::type_checker::do_sizeof_node(mml::sizeof_node *const node, int lvl) {
  // TODO
  //REVIEW
  node->expression()->accept(this, lvl + 2);
  node->type(cdk::primitive_type::create(4, cdk::TYPE_INT));
}