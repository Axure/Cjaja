//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_NULLPOINTEREXCEPTION_HH
#define CJAJA_NULLPOINTEREXCEPTION_HH

#include <java/lang/String.hh>
#include <java/lang/RuntimeException.hh>

using java::lang::String;

namespace java {
namespace lang {
class NullPointerException: public RuntimeException {
 public:
  NullPointerException();

  NullPointerException(const String &message);

};
}
}


#endif //CJAJA_NULLPOINTEREXCEPTION_HH
