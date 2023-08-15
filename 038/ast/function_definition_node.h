#ifndef __MML_AST_FUNCTION_DEFINITION_H__
#define __MML_AST_FUNCTION_DEFINITION_H__

#include <string>
#include <cdk/ast/typed_node.h>
#include <cdk/ast/sequence_node.h>
#include "ast/block_node.h"

namespace mml {

  /**
   * Class for describing function definition nodes.
   */
  class function_definition_node: public cdk::expression_node {
    cdk::sequence_node *_arguments;
    mml::block_node *_block;

  public:
    function_definition_node(int lineno, cdk::sequence_node *arguments, mml::block_node *block) :
        cdk::expression_node(lineno), _arguments(arguments), _block(block) {

        type(cdk::primitive_type::create(0, cdk::TYPE_VOID));
    }

    function_definition_node(int lineno, std::shared_ptr<cdk::basic_type> funType, cdk::sequence_node *arguments, mml::block_node *block) :
        cdk::expression_node(lineno), _arguments(arguments), _block(block) {
            
        type(funType);
    }

  public:
    cdk::sequence_node* arguments() {
      return _arguments;
    }
    cdk::typed_node* argument(size_t ax) {
      return dynamic_cast<cdk::typed_node*>(_arguments->node(ax));
    }
    mml::block_node* block() {
      return _block;
    }

    void accept(basic_ast_visitor *sp, int level) {
      sp->do_function_definition_node(this, level);
    }

  };

} // mml

#endif
