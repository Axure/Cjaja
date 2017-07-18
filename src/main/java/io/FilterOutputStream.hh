//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_FILTEROUTPUTSTREAM_HH
#define CPPAVA_FILTEROUTPUTSTREAM_HH

#include <java/lang/IOException.hh>

#include <java/io/Closeable.hh>
#include <java/io/Flushable.hh>

using java::lang::IOException;

namespace java {

namespace io {
class FilterOutputStream: public Closeable, public Flushable {
 public:
  void close()  override;

  void flush()  override;
};
}
}

#endif //CPPAVA_FILTEROUTPUTSTREAM_HH
