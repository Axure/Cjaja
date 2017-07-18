//
// Created by freet on 2017/7/11.
//

#ifndef CJAJA_ABSTRACTLIST_HH
#define CJAJA_ABSTRACTLIST_HH

#include <java/java.hh>
#include <java/util/AbstractCollection.hh>
#include <java/util/List.hh>
#include <java/util/Arrays.hh>
#include <java/io/Serializable.hh>

namespace java {

namespace util {

template<class E>
class AbstractList: public AbstractCollection<E>,
                    virtual public List<E> {

  virtual bool add(E &e) = 0;
  virtual bool add(E &&e) = 0;

  virtual Iterator<E> &&iterator2() = 0;
  virtual std::shared_ptr<Iterator<E>> iterator() = 0;

  virtual bool isEmpty() = 0;
};
}
}

#endif //CJAJA_ABSTRACTLIST_HH
