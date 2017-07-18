//
// Created by freet on 2017/7/8.
//

#ifndef CPPAVA_CONSUMER_HH
#define CPPAVA_CONSUMER_HH

namespace java {

namespace util {
namespace function {

template<class T>
class Consumer {
 public:
  virtual void accept(T t) = 0;

  virtual Consumer<T> &andThen(Consumer<T> &after) {
//    Objects.requireNonNull(after);
//    return (T t) -> { accept(t); after.accept(t); };
  }
};
}
}
}

#endif //CPPAVA_CONSUMER_HH
