//
// Created by freet on 2017/7/10.
//

#ifndef CJAJA_LINKEDHASHSET_HH
#define CJAJA_LINKEDHASHSET_HH

#include <java/java.hh>
#include <java/io/Serializable.hh>
#include <java/util/Set.hh>

namespace java {

namespace util {

template <class E>
class LinkedHashSet: public Set<E>, public Cloneable, public java::io::Serializable {

};
}
}

#endif //CJAJA_LINKEDHASHSET_HH
