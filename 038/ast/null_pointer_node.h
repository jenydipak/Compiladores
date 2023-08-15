#ifndef __MML_AST_NULL_POINTER_NODE_H__
#define __MML_AST_NULL_POINTER__NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing null nodes.
   */
  class null_pointer_node: public cdk::expression_node {

  public:
    inline null_pointer_node(int lineno) :
        cdk::expression_node(lineno){
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_null_pointer_node(this, level);
    }

  };

} // mml

#endif