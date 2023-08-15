#ifndef __MML_AST_FUNCTION_CALL_NODE_H__
#define __MML_AST_FUNCTION_CALL_NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing function call nodes.
   */
  class function_call_node: public cdk::expression_node {
    cdk::expression_node *_pointer;
    cdk::sequence_node *_argument;

  public:
    inline function_call_node(int lineno, cdk::expression_node *pointer) :
        cdk::expression_node(lineno), _pointer(pointer), _argument(new cdk::sequence_node(lineno)) {
    }

    inline function_call_node(int lineno, cdk::expression_node *pointer, cdk::sequence_node *argument) :
        cdk::expression_node(lineno), _pointer(pointer), _argument(argument) {
    }

  public:
    inline cdk::expression_node* pointer() {
      return _pointer;
    }

    inline cdk::sequence_node* argument() {
      return _argument;
    }

    inline cdk::expression_node *argument(size_t n) {
      return dynamic_cast<cdk::expression_node*>(_argument->node(n));
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_call_node(this, level);
    }

  };

} // mml

#endif