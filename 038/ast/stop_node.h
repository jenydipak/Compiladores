#ifndef __MML_AST_STOP_NODE_H__
#define __MML_AST_STOP_NODE_H__

#include <cdk/ast/basic_node.h>

namespace mml {

  /**
   * Class for describing stop node.
   */
  class stop_node: public cdk::basic_node {
    int _value;

  public:
    inline stop_node(int lineno, int value = 1) :
        cdk::basic_node(lineno), _value(value) {
    }

  public:
    inline int value() const{
      return _value;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_stop_node(this, level);
    }

  };
}

#endif