#ifndef __MML_AST_PRINT_NODE_H__
#define __MML_AST_PRINT_NODE_H__

#include <cdk/ast/expression_node.h>

namespace mml {

  /**
   * Class for describing print nodes.
   */
  class print_node: public cdk::basic_node {
    cdk::sequence_node *_sequence;
    bool _is_println;


  public:
    inline print_node(int lineno, cdk::sequence_node *sequence, bool is_println) :
        cdk::basic_node(lineno), _sequence(sequence), _is_println(is_println) {
    }

    inline cdk::sequence_node *sequence() {
      return _sequence;
    }

    inline bool is_println() {
      return _is_println;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_print_node(this, level);
    }

  };

} // mml

#endif
