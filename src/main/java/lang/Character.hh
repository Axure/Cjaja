//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_CHARACTER_HH
#define CJAJA_CHARACTER_HH

#include <java/java.hh>
#include <java/io/Serializable.hh>
#include <java/lang/Comparable.hh>

namespace java {

namespace lang {
class Character: public java::io::Serializable, public Comparable<Character> {
 private:
  const char value;

 public:
  static const int MIN_SUPPLEMENTARY_CODE_POINT = 0x010000;

  static const char MIN_HIGH_SURROGATE = '\xD8\x00';

  static const char MIN_LOW_SURROGATE = '\xDC\x00';

  static const int MIN_CODE_POINT = 0x000000;

  static const int MAX_CODE_POINT = 0X10FFFF;

 public:
  static boolean isValidCodePoint(int codePoint);

  static char highSurrogate(int codePoint);

  static char lowSurrogate(int codePoint);

 public:
  int compareTo(Character &anotherCharacter) override {
    return compare(this->value, anotherCharacter.value);
  }

  int compareTo(Character &&anotherCharacter) override {
    return compare(this->value, anotherCharacter.value);
  }

 public:
  static int compare(char x, char y) {
    return x - y;
  }
};
}
}

#endif //CJAJA_CHARACTER_HH
