//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_FLUSHABLE_HH
#define CPPAVA_FLUSHABLE_HH

#include <java/lang/IOException.hh>

using java::lang::IOException;

namespace java {

namespace io {

/**
 * @abstract
 */
class Flushable {
 public:
  virtual void flush()  = 0;
};

}
}
#endif //CPPAVA_FLUSHABLE_HH
