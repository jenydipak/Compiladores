#ifndef __MML_TARGETS_SYMBOL_H__
#define __MML_TARGETS_SYMBOL_H__

#include <string>
#include <memory>
#include <cdk/types/basic_type.h>

namespace mml {

  class symbol {
    std::shared_ptr<cdk::basic_type> _type;
    std::string _name;
    long _value; // hack!
    bool _constant; 
    int _qualifier;
    bool _initialized; 
    int _offset = 0; 
    bool _function; 
    bool _forward = false;

  public:
    symbol(bool constant, int qualifier, std::shared_ptr<cdk::basic_type> type, const std::string &name, bool initialized,
           bool function, bool forward = false) :
           _constant(constant), _qualifier(qualifier), _type(type), _name(name), _initialized(initialized),
           _function(function), _forward(forward), _value(0){

           }
    /*symbol(std::shared_ptr<cdk::basic_type> type, const std::string &name, long value) :
        _type(type), _name(name), _value(value){
    }*/

    virtual ~symbol() {
      // EMPTY
    }

    std::shared_ptr<cdk::basic_type> type() const {
      return _type;
    }
    bool is_typed(cdk::typename_type name) const {
      return _type->name() == name;
    }
    const std::string &name() const {
      return _name;
    }
    long value() const {
      return _value;
    }
    long value(long v) {
      return _value = v;
    }
    bool is_main() const {
      return _name == "_main";
    }
    void set_type(std::shared_ptr<cdk::basic_type> t) {
      _type = t;
    }
  };

  inline auto make_symbol(bool constant, int qualifier, std::shared_ptr<cdk::basic_type> type, const std::string &name,
                          bool initialized, bool function, bool forward = false) {
      return std::make_shared<symbol>(constant, qualifier, type, name, initialized, function, forward);
    }

} // mml

#endif
