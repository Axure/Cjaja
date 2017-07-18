//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_INDEXOUTOFBOUNDSEXCEPTION_HH
#define CAPPA_INDEXOUTOFBOUNDSEXCEPTION_HH

#include <java/lang/String.hh>
#include <java/lang/RuntimeException.hh>

using java::lang::String;

namespace java {
namespace lang {

class IndexOutOfBoundsException: public RuntimeException {
 public:

  IndexOutOfBoundsException(String s) : RuntimeException(s) {
  }
};
}
}

#endif //CAPPA_INDEXOUTOFBOUNDSEXCEPTION_HH
