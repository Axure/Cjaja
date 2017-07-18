//
// Created by freet on 2017/7/17.
//

#include "NullPointerException.hh"

java::lang::NullPointerException::NullPointerException(const String &message) : RuntimeException(message) {

}

java::lang::NullPointerException::NullPointerException() : RuntimeException() {

}
