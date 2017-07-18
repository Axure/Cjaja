//
// Created by freet on 2017/7/18.
//

#include <memory>
#include "StringBuffer.hh"

/**
 * TODO: @unimplemented
 * @param csq
 * @return
 */
Appendable &java::lang::StringBuffer::append(CharSequence &csq) {

  return *this;
}

/**
 * TODO: @unimplemented
 * @param csq
 * @param start
 * @param end
 * @return
 */
Appendable &java::lang::StringBuffer::append(CharSequence &csq, int start, int end) {

  return *this;
}

Appendable &java::lang::StringBuffer::append(char c) {

//  toStringCache = null;
  AbstractStringBuilder::append(c);
  return *this;
}

int java::lang::StringBuffer::length() {
  return 0;
}

char java::lang::StringBuffer::charAt(int i) {
  return 0;
}

std::shared_ptr<CharSequence> java::lang::StringBuffer::subSequence(int start, int end) {
  return std::make_shared<String>(AbstractStringBuilder::substring(start, end));
}

java::lang::String java::lang::StringBuffer::toString() {
  return String();
}

StringBuffer::StringBuffer(int i): AbstractStringBuilder(i) {

}

Appendable &StringBuffer::append(CharSequence &&csq) {
  return *this;
}

Appendable &StringBuffer::append(CharSequence &&csq, int start, int end) {
  return *this;
}
