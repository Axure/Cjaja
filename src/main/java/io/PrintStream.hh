//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_PRINTSTREAM_HH
#define CPPAVA_PRINTSTREAM_HH

#include <java/lang/String.hh>
#include <java/lang/Object.hh>
#include <java/io/FilterOutputStream.hh>

using java::lang::Object;
using java::lang::String;

namespace java {

namespace io {
class PrintStream: public FilterOutputStream {

  /**
   * Temporary buffer used to hold writes of strings and single characters
   */
 private:
  char *writeBuffer;

  /**
   * Size of writeBuffer, must be >= 1
   */
  static constexpr int WRITE_BUFFER_SIZE = 1024;

 protected:
  Object lock;

 public:
  void print(int i);

  void println(int i);

  void print(String &s);

  void println(String &i);

  void print(String &&i);

  void println(String &&i);

 private:
  void write(String &s);

  void write(String &&s);
};
}
}

#endif //CPPAVA_PRINTSTREAM_HH
