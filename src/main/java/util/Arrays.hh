//
// Created by freet on 2017/7/11.
//

#ifndef CJAJA_ARRAYS_HH
#define CJAJA_ARRAYS_HH

#include <java/java.hh>
#include <java/util/stream/Stream.hh>

namespace java {

namespace util {

template<class T>
class Stream;

class Arrays {
 public:
  template<class T>
  static Stream<T> stream(T array[]) {
//    return stream(array, 0, array.length);
  }

  template<class T>
  static T *copyOf(T *original, int newLength) {

    T *copy =
//    T* copy = (std::is_same<T, U>::value)
//    ? (T*) malloc(sizeof(T)*newLength)
        (T *) malloc(sizeof(T) * newLength);
//    : (T*) Array.newInstance(newType.getComponentType(), newLength);
    System::arraycopy(original, 0, copy, 0,
                      Math::min(fdsafasd2(original), newLength));
    return copy;
//    return (T *) copyOf(original, newLength, (*(T*)nullptr));
  }

  template<class T>
  static Array<T> copyOf(Array<T> &original, int newLength) {

    Array<T> copy = Array<T>(newLength);
    System::arraycopy(original, 0, copy, 0,
                      Math::min(original.length, newLength));
    return copy;
//    return (T *) copyOf(original, newLength, (*(T*)nullptr));
  }

  template<class T, class U>
  static T *copyOf(U *original, int newLength, T dummy) {
    T *copy =
//    T* copy = (std::is_same<T, U>::value)
//    ? (T*) malloc(sizeof(T)*newLength)
        (T *) malloc(sizeof(T) * newLength);
//    : (T*) Array.newInstance(newType.getComponentType(), newLength);
    System::arraycopy(original, 0, copy, 0,
                      Math::min(sizeof(original), newLength));
    return copy;
  }
};
}
}


#endif //CJAJA_ARRAYS_HH
