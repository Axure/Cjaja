//
// Created by freet on 2017/7/18.
//

#include "AbstractStringBuilder.hh"

#include <java/util/Arrays.hh>
#include <java/lang/OutOfMemoryError.hh>
#include <java/lang/StringIndexOutOfBoundsException.hh>

using java::util::Arrays;

Appendable &java::lang::AbstractStringBuilder::append(char c) {

  ensureCapacityInternal(count + 1);
  value[count++] = c;
  return *this;
}

void java::lang::AbstractStringBuilder::ensureCapacityInternal(int minimumCapacity) {

  // overflow-conscious code
  if (minimumCapacity - value.length > 0) {
    value = Arrays::copyOf(value,
                           newCapacity(minimumCapacity));
  }
}

int AbstractStringBuilder::newCapacity(int minCapacity) {
  // overflow-conscious code
  int newCapacity = (value.length << 1) + 2;
  if (newCapacity - minCapacity < 0) {
    newCapacity = minCapacity;
  }
  return (newCapacity <= 0 || MAX_ARRAY_SIZE - newCapacity < 0)
         ? hugeCapacity(minCapacity)
         : newCapacity;
}

int AbstractStringBuilder::hugeCapacity(int minCapacity) {

  if (Integer::MAX_VALUE - minCapacity < 0) { // overflow
    throw new OutOfMemoryError();
  }
  return (minCapacity > MAX_ARRAY_SIZE)
         ? minCapacity : MAX_ARRAY_SIZE;
}

String AbstractStringBuilder::substring(int start, int end) {

  if (start < 0)
    throw new StringIndexOutOfBoundsException(start);
  if (end > count)
    throw new StringIndexOutOfBoundsException(end);
  if (start > end)
    throw new StringIndexOutOfBoundsException(end - start);
  return String(value, start, end - start);
}

AbstractStringBuilder::AbstractStringBuilder(int capacity) {
  value = Array<char>(capacity);
}
