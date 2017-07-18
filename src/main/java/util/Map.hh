//
// Created by freet on 2017/7/10.
//

#ifndef CJAJA_MAP_HH
#define CJAJA_MAP_HH

#include <java/java.hh>
#include <java/util/Set.hh>

namespace java {
namespace util {

template<class K, class V>
class Map {
 public:
  virtual int size() = 0;

  virtual bool isEmpty() = 0;

  virtual bool containsKey(Object &key) = 0;

  virtual bool containsValue(Object &value) = 0;

  virtual V get(Object &key) = 0;

  virtual V put(K &key, V &value) = 0;

  virtual V remove(Object &key) = 0;

  virtual void putAll(Map<K, V> m) = 0; /* Probably should be templatized */

  virtual void clear() = 0;

 public:
  virtual Set<K> keySet() = 0;
};

}
}


#endif //CJAJA_MAP_HH
