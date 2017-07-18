//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_CHARSEQUENCE_HH
#define CPPAVA_CHARSEQUENCE_HH

//#include <java/lang/String.hh>

#include <memory>

namespace java {

namespace lang {

class String;

class CharSequence {
 public:
  virtual int length() = 0;

  virtual char charAt(int i) = 0;

  virtual std::shared_ptr<CharSequence> subSequence(int s, int e) = 0;

  virtual String toString() = 0;
//  IntStream chars();
//  IntStream codePoints();
};

}
}

#endif //CPPAVA_CHARSEQUENCE_HH
