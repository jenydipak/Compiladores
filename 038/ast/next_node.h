#ifndef __MML_AST_NEXT_NODE_H__
#define __MML_AST_NEXT_NODE_H__

#include <cdk/ast/basic_node.h>

namespace mml {

  /**
   * Class for describing next node.
   */
  class next_node: public cdk::basic_node {
    int _value;

  public:
    inline next_node(int lineno, int value = 1) :
        cdk::basic_node(lineno), _value(value) {
    }

  public:
    inline int value() const{
      return _value;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_next_node(this, level);
    }

  };
}

#endif
