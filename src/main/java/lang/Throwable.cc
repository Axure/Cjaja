//
// Created by freet on 2017/7/11.
//

#include "Throwable.hh"

#include <java/io/PrintStream.hh>
#include <java/io/Serializable.hh>

#include <java/lang/System.hh>

using java::lang::String;
using java::io::PrintStream;

using java::io::Serializable;

java::lang::Throwable::Throwable(String message) {

//    fillInStackTrace();
  detailMessage = message;
}

void java::lang::Throwable::printStackTrace() {
  this->printStackTrace(System::err);
}

void java::lang::Throwable::printStackTrace(PrintStream &s) {

//  this->printStackTrace(WrappedPrintStream(s));
}

void java::lang::Throwable::printStackTrace(PrintStream &&s) {

}

Throwable::Throwable() {

}
