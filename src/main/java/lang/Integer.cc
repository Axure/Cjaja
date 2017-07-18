//
// Created by freet on 2017/7/7.
//

#include "Integer.hh"

java::lang::Integer::Integer(int i) : value(i) {

}

java::lang::Integer::Integer(java::lang::String s) {

}

java::lang::Integer::~Integer() {

}

java::lang::String java::lang::Integer::toString(int i, int radix) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toUnsignedString(int i, int radix) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toHexString(int i) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toOctalString(int i) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toBinaryString(int i) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toString(int i) {
  return java::lang::String();
}

java::lang::String java::lang::Integer::toUnsignedString(int i) {
  return java::lang::String();
}

int java::lang::Integer::parseInt(java::lang::String s, int radix) {
  return 0;
}

int java::lang::Integer::parseInt(java::lang::String s) {
  return 0;
}

int java::lang::Integer::parseUnsignedInt(java::lang::String s, int radix) {
  return 0;
}

int java::lang::Integer::parseUnsignedInt(java::lang::String s) {
  return 0;
}

java::lang::Integer java::lang::Integer::valueOf(java::lang::String s, int radix) {
  return java::lang::Integer(0);
}

java::lang::Integer java::lang::Integer::valueOf(java::lang::String s) {
  return java::lang::Integer(0);
}

java::lang::Integer java::lang::Integer::valueOf(int i) {
  return java::lang::Integer(0);
}

int java::lang::Integer::compareTo(java::lang::Integer &o) {
  if (this->value > o.value) {
    return 1;
  } else {
    if (this->value < o.value) {
      return -1;
    } else {
      return 0;
    }
  }
}

int java::lang::Integer::compareTo(java::lang::Integer &&o) {
  if (this->value > o.value) {
    return 1;
  } else {
    if (this->value < o.value) {
      return -1;
    } else {
      return 0;
    }
  }
}
