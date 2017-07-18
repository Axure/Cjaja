//
// Created by freet on 2017/7/18.
//

#ifndef CJAJA_ABSTRACTSTRINGBUILDER_HH
#define CJAJA_ABSTRACTSTRINGBUILDER_HH

#include <java/io/Serializable.hh>

#include <java/lang/Appendable.hh>
#include <java/lang/Array.hh>
#include <java/lang/Integer.hh>


namespace java {

namespace lang {

class AbstractStringBuilder: public Appendable {
 public:
  AbstractStringBuilder(int capacity);

  Appendable &append(char c) override;

 public:

  String substring(int start, int end);

 private:
  void ensureCapacityInternal(int minimumCapacity);

  int newCapacity(int minCapacity);

  int hugeCapacity(int minCapacity);

 private:
  Array<char> value;

  int count;

 private:
  static constexpr int MAX_ARRAY_SIZE = Integer::MAX_VALUE - 8;
};
}
}

#endif //CJAJA_ABSTRACTSTRINGBUILDER_HH
