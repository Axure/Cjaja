//
// Created by freet on 2017/7/12.
//

#ifndef CJAJA_ARRAY_HH
#define CJAJA_ARRAY_HH

#include <typeinfo>
#include <cstdio>
#include <cstdlib>
#include <initializer_list>
#include <java/java.hh>

#define FILE_NAME "java/lang/Array.hh"
namespace java {
namespace lang {

template<class T>
class Array {
 public:

  int length = 0;

 private:
  T *storage = nullptr;

 public:
  Array() {

    printf("Constructing Array<%s> of length %d\n", typeid(T).name(), 0);
  };

  Array(std::initializer_list<T> &list) : length(list.size()) {

    printf("Constructing Array<%s> of length %d\n", typeid(T).name(), length);
    this->storage = new T[length]();
    int i = 0;
    for (auto &element: list) {
      this->storage[i++] = element;
    }
  }

  Array(std::initializer_list<T> &&list) : length(list.size()) {

    printf("Constructing Array<%s> of length %d\n", typeid(T).name(), length);
    this->storage = new T[length]();
    int i = 0;
    for (auto &element: list) {
      this->storage[i++] = element;
    }
  }

  Array(int length) : length(length) {
    printf("Constructing Array<%s> of length %d\n", typeid(T).name(), length);
    this->storage = new T[length]();
  };

  ~Array() {
    printf("destroying Array<%s>\n", typeid(T).name());
    if (this->storage != nullptr) {
      delete[] this->storage;
    }
  };


  T &operator[](int index) {
    return ((this->storage))[index];
  }

  const T &operator[](int index) const {
    return ((this->storage))[index];
  }
};

}
}


#endif //CJAJA_ARRAY_HH
