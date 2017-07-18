//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_OBJECT_HH
#define CPPAVA_OBJECT_HH

#include <cstdlib>
#include <cstring>

namespace java {

namespace lang {
class Object {
 private:
  void *storage = nullptr;

 public:

  Object();

  template<class T>
  Object(T &value) {
    this->storage = new T(value);
  }

  template<class T>
  Object(T &&value) {
    this->storage = new T(value);
  }

  template<class T>
  void operator=(T &value) {
    if (this->storage != nullptr) delete this->storage;
    this->storage = new T(value);
  }

  template<class T>
  void operator=(T &&value) {
    if (this->storage != nullptr) delete this->storage;
    this->storage = new T(value);
  }

  ~Object();
};
}
}

#endif //CPPAVA_OBJECT_HH
