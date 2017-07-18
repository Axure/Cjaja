//
// Created by freet on 2017/7/10.
//

#ifndef CJAJA_ABSTRACTCOLLECTION_HH
#define CJAJA_ABSTRACTCOLLECTION_HH

#include <java/util/Collection.hh>
namespace java {

namespace util {

template<class E>
class AbstractCollection: public Collection<E> {
 public:
  virtual int size() = 0;
};
}
}

#endif //CJAJA_ABSTRACTCOLLECTION_HH
