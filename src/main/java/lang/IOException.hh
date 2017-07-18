//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_IOEXCEPTION_HH
#define CPPAVA_IOEXCEPTION_HH

#include <java/lang/Exception.hh>

namespace java {

namespace lang {

class IOException: public Exception {

 public:
  IOException(String message) : Exception(message) {

  }
};

}
}

#endif //CPPAVA_IOEXCEPTION_HH
