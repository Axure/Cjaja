//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_THROWABLE_HH
#define CPPAVA_THROWABLE_HH

#include <java/lang/String.hh>
#include <java/lang/Object.hh>

namespace java {
namespace io {

class PrintStream;
}
namespace lang {


class Throwable: public java::io::Serializable {

 private:
  String detailMessage;

 public:
  Throwable();
  Throwable(String message);

 public:
  void printStackTrace();

/**
 * Prints this throwable and its backtrace to the specified print stream.
 *
 * @param s {@code PrintStream} to use for output
 */
  void printStackTrace(java::io::PrintStream &s);

  void printStackTrace(java::io::PrintStream &&s);

 private:
  class PrintStreamOrWriter {
   public:
    Object lock();

    void println(Object &o);

    void println(Object &&o);
  };

  class WrapperPrintStream: public PrintStreamOrWriter {

  };
};

}
}
#endif //CPPAVA_THROWABLE_HH
