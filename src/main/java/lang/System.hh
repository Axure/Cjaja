//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_SYSTEM_H
#define CPPAVA_SYSTEM_H

#include <cstring>

#include <java/io/PrintStream.hh>
#include <java/lang/Object.hh>
#include <java/lang/Array.hh>


namespace java {

namespace lang {

template<class T>
class Array;

class System {

 public:
  /* const */ static java::io::PrintStream out;

  /* const */ static java::io::PrintStream err;

 public:
//  static void arraycopy(Object src, int srcPos,
//                        Object dest, int destPos,
//                        int length);

  template<class S>
  static void arraycopy(S src[], int srcPos,
                        S dest[], int destPos,
                        int length) {
    ::memcpy(dest + destPos, src + srcPos, sizeof(S) * length);
  }

  template<class S>
  static void arraycopy(Array<S> &src, int srcPos,
                        Array<S> &dest, int destPos,
                        int length) {
    for (int i = 0; i < length; ++i) {
      dest[destPos + i] = src[srcPos + i];
    }
  }
};

}

}


#endif //CPPAVA_SYSTEM_H
