//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_INTEGER_HH
#define CPPAVA_INTEGER_HH

#include "./Comparable.hh"

#include "./String.hh"

namespace java {

namespace lang {

class Integer: public Comparable<Integer> {
 public:
  static constexpr int MAX_VALUE = 0x7fffffff;

 public:
  Integer(int);

  Integer(String);

  ~Integer();

  /**
   * Static methods
   */
 public:
  static String toString(int i, int radix);

  static String toUnsignedString(int i, int radix);

  static String toHexString(int i);

  static String toOctalString(int i);

  static String toBinaryString(int i);

  static String toString(int i);

  static String toUnsignedString(int i);

  static int parseInt(String s, int radix);

  static int parseInt(String s);

  static int parseUnsignedInt(String s, int radix);

  static int parseUnsignedInt(String s);

  static Integer valueOf(String s, int radix);

  static Integer valueOf(String s);

  static Integer valueOf(int i);


  int compareTo(Integer &o) override;

  int compareTo(Integer &&o) override;

 public:

 private:
  int value;
};
}
}

#endif //CPPAVA_INTEGER_HH
