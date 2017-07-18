//
// Created by freet on 2017/7/8.
//

#ifndef CPPAVA_ITERABLE_HH
#define CPPAVA_ITERABLE_HH

#include <memory>
#include <java/util/Iterator.hh>
#include <java/util/function/Consumer.hh>
using java::util::Iterator;

namespace java {

namespace lang {

template<class T>
class Iterable {
 public:
  /**
   * Returns an iterator over elements of type {@code T}.
   *
   * @return an Iterator.
   *
   */
  virtual Iterator<T> &&iterator2() = 0;
  virtual std::shared_ptr<Iterator<T>> iterator() = 0;
  virtual Iterator<T> &&begin() = 0;
  virtual Iterator<T> &&end() = 0;


  virtual void forEach(Consumer<T> &action) {
//    Objects.requireNonNull(action);
//    for (auto && t : *this) { /** Needs to be modified. No such semantics in C++ */
//      action.accept(t);
//    }
    auto && iterator = this->iterator();
    while (iterator->hasNext()) {
      action.accept(iterator->next());
    }
  }

  virtual void forEach(Consumer<T> &&action) {}
};
}
}


#endif //CPPAVA_ITERABLE_HH
