//
// Created by freet on 2017/7/8.
//

#ifndef CPPAVA_ITERATOR_HH
#define CPPAVA_ITERATOR_HH

#include <java/util/function/Consumer.hh>

using java::util::function::Consumer;

namespace java {

namespace util {

class IteratorBase {

 protected:
  int cursor;
};

template<class E>
class Iterator: public IteratorBase {
 public:

  // these three methods form the basis of an iterator for use with a range-based for loop
//  virtual bool operator!= (const Iterator& other) = 0;

  // this method must be defined after the definition of IntVector since it needs to use it
//  virtual E operator* () = 0;

//  virtual Iterator& operator++ () = 0;

  virtual bool hasNext() = 0;

  virtual E next() = 0;

  virtual void remove() {

  };

  virtual void forEachRemaining(Consumer<E> &action) {
//    Objects.requireNonNull(action);
    while (hasNext())
      action.accept(next());
  };

  virtual void forEachRemaining(Consumer<E> &&action) {

  };
};

}

}

#endif //CPPAVA_ITERATOR_HH
