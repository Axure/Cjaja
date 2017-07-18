//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_BASESTREAM_HH
#define CAPPA_BASESTREAM_HH

#include <java/lang/AutoCloseable.hh>
#include <java/util/Iterator.hh>
#include <type_traits>
using java::lang::AutoCloseable;
using java::util::Iterator;

namespace java {
namespace util {
namespace stream {


template<class T, class S>
class BaseStream: public virtual AutoCloseable {
  static_assert(std::is_base_of<BaseStream<T,S>, S>::value, "S should be subclass of BaseStream<T,S>");
 public:
  virtual Iterator<T> iterator() = 0;

  /* spliterator */
  virtual bool isParallel() = 0;

  virtual S sequential() = 0;

  virtual S parallel() = 0;

  virtual S unordered() = 0;
//  S onClose(Runnable closeHandler);

  virtual void close() override = 0;
};

}
}
}

#endif //CAPPA_BASESTREAM_HH
