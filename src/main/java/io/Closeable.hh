//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_CLOSEABLE_HH
#define CPPAVA_CLOSEABLE_HH

#include <java/lang/IOException.hh>
#include <java/lang/AutoCloseable.hh>

using java::lang::IOException;
using java::lang::AutoCloseable;

namespace java {

namespace io {
class Closeable: public AutoCloseable {
 public:
  virtual void close()  override = 0;
};
}
}

#endif //CPPAVA_CLOSEABLE_HH
