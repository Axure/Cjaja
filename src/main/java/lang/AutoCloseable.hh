//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_AUTOCLOSEABLE_HH
#define CPPAVA_AUTOCLOSEABLE_HH

#include <java/lang/IOException.hh>

namespace java {

namespace lang {

/**
 * A {@code Closeable} is a source or destination of data that can be closed.
 * The close method is invoked to release resources that the object is
 * holding (such as open files).
 *
 */
class AutoCloseable {
 public:
  virtual void close()  = 0;
};
}
}

#endif //CPPAVA_AUTOCLOSEABLE_HH
