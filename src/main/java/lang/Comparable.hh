//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_COMPARABLE_HH
#define CPPAVA_COMPARABLE_HH

namespace java {

namespace lang {


template<class T>
class Comparable {
 public:
  virtual int compareTo(T &o) = 0;

  virtual int compareTo(T &&o) = 0;
};

}
}

#endif //CPPAVA_COMPARABLE_HH
