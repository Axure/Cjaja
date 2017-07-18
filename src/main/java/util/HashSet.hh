//
// Created by freet on 2017/7/10.
//

#ifndef CJAJA_HASHSET_HH
#define CJAJA_HASHSET_HH

#include <java/java.hh>
#include <java/util/AbstractSet.hh>
#include <java/util/Set.hh>
#include <java/io/Serializable.hh>

namespace java {

namespace util {

template<class E>
class HashSet: public AbstractSet<E>,
               virtual public Set<E>, virtual public Cloneable, virtual public java::io::Serializable {

};
}
}

#endif //CJAJA_HASHSET_HH
