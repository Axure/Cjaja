//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_EXCEPTION_HH
#define CPPAVA_EXCEPTION_HH

#include <java/lang/String.hh>
#include <java/lang/Throwable.hh>

using java::lang::String;

namespace java {

namespace lang {
class Exception: public Throwable {
 public:
  Exception() : Throwable() {};

  Exception(String message) : Throwable(message) {

  }
};
}
}

#endif //CPPAVA_EXCEPTION_HH
