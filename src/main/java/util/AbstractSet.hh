//
// Created by freet on 2017/7/10.
//

#ifndef CJAJA_ABSTRACTSET_HH
#define CJAJA_ABSTRACTSET_HH

#include <java/util/AbstractCollection.hh>
#include <java/util/Set.hh>
namespace java {

namespace util {

template<class E>
class AbstractSet: public AbstractCollection<E>,
                   virtual public Set<E> {

};
}
}

#endif //CJAJA_ABSTRACTSET_HH
