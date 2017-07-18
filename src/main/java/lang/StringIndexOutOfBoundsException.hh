//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_STRINGINDEXOUTOFBOUNDSEXCEPTION_HH
#define CAPPA_STRINGINDEXOUTOFBOUNDSEXCEPTION_HH

#include <java/lang/IndexOutOfBoundsException.hh>

namespace java {
namespace lang {

class StringIndexOutOfBoundsException: public IndexOutOfBoundsException {
 public:
  StringIndexOutOfBoundsException(int index) : IndexOutOfBoundsException("String index out of range: " + index) {

  }
};
}
}
#endif //CAPPA_STRINGINDEXOUTOFBOUNDSEXCEPTION_HH
