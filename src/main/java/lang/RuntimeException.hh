//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_RUNTIMEEXCEPTION_HH
#define CAPPA_RUNTIMEEXCEPTION_HH

#include <java/lang/String.hh>
#include <java/lang/Exception.hh>

using java::lang::String;

namespace java {
namespace lang {


class RuntimeException: public Exception {
 public:
  RuntimeException() : Exception() {

  }

  RuntimeException(String message) : Exception(message) {
  }
};

}
}


#endif //CAPPA_RUNTIMEEXCEPTION_HH
