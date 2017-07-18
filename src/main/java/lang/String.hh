//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_STRING_HH
#define CPPAVA_STRING_HH

#include <cstdint>
#include <memory>
#include <java/lang/String.hh>

namespace java {

namespace lang {
//class CharSequence;
}
}

#include <java/io/Serializable.hh>
#include <java/lang/Comparable.hh>
#include <java/lang/CharSequence.hh>

using java::lang::CharSequence;

namespace java {

namespace lang {

template <class T>
class Array;

String operator+(const char *str, String &&another);

String operator+(const char *str, String &another);

class String: public java::io::Serializable, public Comparable<String>, public CharSequence {
 public:

  String();

  virtual ~String();

  String(String &s);

  String(const String &s);

  String(String &&s);

  String(char s[]);

  String(const char s[]);

  String(char value[], int offset, int count);
  String(Array<char> &value, int offset, int count);

  String(int codePoints[], int offset, int count);


//  String(byte bytes[]);

 public:
  int length();

  char charAt(int i) override;

  std::shared_ptr<CharSequence> subSequence(int s, int e) override;

  String toString() override;

  int indexOf(int ch) const;

  int indexOf(int ch, int fromIndex) const;

  String substring(int beginIndex, int endIndex);

 public:
  void operator=(String &another);

  void operator=(const String &another);

  void operator=(String &&another);

  String operator+(String &another) &;

  String operator+(String &another) &&;

  String operator+(String &&another) &;

  String operator+(String &&another) &&;

 public:
  friend String operator+(const char *str, String &another);

  friend String operator+(const char *str, String &&another);

 public:
  int compareTo(String &o) override;

  int compareTo(String &&o) override;

 public:
  void getChars(int srcBegin, int srcEnd, char dst[], int dstBegin);

 private:
  /**
   * TODO: change to Array<char>
   */
  char *value = nullptr;

  int hash;

  constexpr static long serialVersionUID = 213123;

 private:
  int indexOfSupplementary(int ch, int fromIndex) const;

};

}
}

#endif //CPPAVA_STRING_HH
