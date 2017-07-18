//
// Created by freet on 2017/7/18.
//

#ifndef CJAJA_STRINGBUFFER_HH
#define CJAJA_STRINGBUFFER_HH

#include <java/io/Serializable.hh>
#include <java/lang/AbstractStringBuilder.hh>
#include <java/lang/Comparable.hh>
#include <java/lang/CharSequence.hh>
#include <java/lang/Array.hh>

using java::lang::CharSequence;

namespace java {

namespace lang {
class StringBuffer: public AbstractStringBuilder,
                    public java::io::Serializable, public CharSequence {
 public:
  StringBuffer(int i);

  Appendable &append(CharSequence &csq) override;
  Appendable &append(CharSequence &&csq) override;

  Appendable &append(CharSequence &csq, int start, int end) override;
  Appendable &append(CharSequence &&csq, int start, int end) override;

  Appendable &append(char c) override;

  int length() override;

  char charAt(int i) override;

  std::shared_ptr<CharSequence> subSequence(int s, int e) override;

  String toString() override;

 private:
  Array<char> toStringCache;
};
}
}


#endif //CJAJA_STRINGBUFFER_HH
