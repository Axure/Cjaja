//
// Created by freet on 2017/7/8.
//

#ifndef CPPAVA_COLLECTION_HH
#define CPPAVA_COLLECTION_HH

//#include <memory>

#include <java/util/Iterator.hh>
#include <java/lang/Iterable.hh>
namespace java {

namespace util {


template<class E>
class Collection: virtual public Iterable<E> {
 public:
  virtual int size() = 0;

  virtual bool add(E &e) = 0;
  virtual bool add(E &&e) = 0;

  virtual Iterator<E> &&iterator2() = 0;
  virtual std::shared_ptr<Iterator<E>> iterator() = 0;

  virtual bool isEmpty() = 0;

};

}
}

#endif //CPPAVA_COLLECTION_HH
