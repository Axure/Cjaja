//
// Created by freet on 2017/7/7.
//
#include <cstring>
#include "String.hh"
#include <java/lang/System.hh>
#include <java/lang/StringIndexOutOfBoundsException.hh>
#include <java/lang/Character.hh>
#include <utility>
#include <cstdio>

using java::lang::System;
using java::lang::StringIndexOutOfBoundsException;

int java::lang::String::compareTo(java::lang::String &o) {
  return 0;
}

int java::lang::String::compareTo(java::lang::String &&o) {
  return 0;
}

java::lang::String::String() {

}

java::lang::String::~String() {
  if (this->value != nullptr) delete[] this->value;
}

java::lang::String::String(java::lang::String &s) : String(s.value) {
}

java::lang::String::String(const java::lang::String &s) : String(s.value) {
}

java::lang::String::String(java::lang::String &&s) {
  if (this->value != nullptr) delete[] this->value;
  this->value = s.value;
  s.value = nullptr;
}

java::lang::String::String(char *s) {
  if (this->value != nullptr) delete[] this->value;
  this->value = new char[strlen(s) + 1]();
  strcpy(this->value, s);
}

java::lang::String::String(const char *s) {
  if (this->value != nullptr) delete[] this->value;
  this->value = new char[strlen(s) + 1]();
  strcpy(this->value, s);
}

java::lang::String::String(char *value, int offset, int count) {

}

java::lang::String::String(int *codePoints, int offset, int count) {

}

//java::lang::String::String(byte *bytes) {
//
//}

void java::lang::String::getChars(int srcBegin, int srcEnd, char *dst, int dstBegin) {
  if (srcBegin < 0) {
    throw StringIndexOutOfBoundsException(srcBegin);
  }
  if (srcEnd > strlen(value)) {
    throw StringIndexOutOfBoundsException(srcEnd);
  }
  if (srcBegin > srcEnd) {
    throw StringIndexOutOfBoundsException(srcEnd - srcBegin);
  }
  System::arraycopy(value, srcBegin, dst, dstBegin, srcEnd - srcBegin);
}

void String::operator=(String &another) {
  if (this->value != nullptr) delete[] this->value;
  this->value = new char[strlen(another.value) + 1]();
  strcpy(this->value, another.value);
}

void String::operator=(const String &another) {
  if (this->value != nullptr) delete[] this->value;
  this->value = new char[strlen(another.value) + 1]();
  strcpy(this->value, another.value);
}

void String::operator=(String &&another) {
  this->value = another.value;
  another.value = nullptr;
}

int String::length() {
  return (int) strlen(this->value);
}

char String::charAt(int index) {
  if ((index < 0) || (index >= this->length())) {
    throw new StringIndexOutOfBoundsException(index);
  }
  return value[index];
}

std::shared_ptr<CharSequence> String::subSequence(int s, int e) {
  return std::make_shared<String>(*this);
}

String String::toString() {
  return *this;
}

String String::operator+(String &another) &{
  String sum;
  sum.value = new char[this->length() + another.length() + 1]();
  strcpy(sum.value, this->value);
  strcpy(sum.value + this->length(), another.value);
  return sum;
}


String String::operator+(String &another) &&{
  String sum;
  sum.value = new char[this->length() + another.length() + 1]();
  strcpy(sum.value, this->value);
  strcpy(sum.value + this->length(), another.value);
  return sum;
}

String String::operator+(String &&another) &{
  String sum;
  sum.value = new char[this->length() + another.length() + 1]();
  strcpy(sum.value, this->value);
  strcpy(sum.value + this->length(), another.value);
  return sum;
}

String String::operator+(String &&another) &&{
//  printf("LOG4: %d,\"%s\",\"%s\"\n", this->length(), this->value, another.value);
  String sum;
  sum.value = new char[this->length() + another.length() + 1]();
  strcpy(sum.value, this->value);
  strcpy(sum.value + this->length(), another.value);
  return sum;
}

String java::lang::operator+(const char *str, String &another) {
  return String(str) + another;
}

String java::lang::operator+(const char *str, String &&another) {
  return String(str) + another;
}

int String::indexOf(int ch) const {
  return indexOf(ch, 0);
}

int String::indexOf(int ch, int fromIndex) const {
  const int max = strlen(value);
  if (fromIndex < 0) {
    fromIndex = 0;
  } else if (fromIndex >= max) {
    // Note: fromIndex might be near -1>>>1.
    return -1;
  }

  if (ch < Character::MIN_SUPPLEMENTARY_CODE_POINT) {
    // handle most cases here (ch is a BMP code point or a
    // negative value (invalid code point))
    const char *value = this->value;
    for (int i = fromIndex; i < max; i++) {
      if (value[i] == ch) {
        return i;
      }
    }
    return -1;
  } else {
    return indexOfSupplementary(ch, fromIndex);
  }
}

int String::indexOfSupplementary(int ch, int fromIndex) const {
  if (Character::isValidCodePoint(ch)) {
    const char *value = this->value;
    const char hi = Character::highSurrogate(ch);
    const char lo = Character::lowSurrogate(ch);
    const int max = strlen(value) - 1;
    for (int i = fromIndex; i < max; i++) {
      if (value[i] == hi && value[i + 1] == lo) {
        return i;
      }
    }
  }
  return -1;
}

String::String(Array<char> &value, int offset, int count) {

}

String String::substring(int beginIndex, int endIndex) {

  if (beginIndex < 0) {
    throw new StringIndexOutOfBoundsException(beginIndex);
  }
  if (endIndex > strlen(value)) {
    throw new StringIndexOutOfBoundsException(endIndex);
  }
  int subLen = endIndex - beginIndex;
  if (subLen < 0) {
    throw new StringIndexOutOfBoundsException(subLen);
  }
  return ((beginIndex == 0) && (endIndex == strlen(value))) ? *this
                                                           : String(value, beginIndex, subLen);
}

