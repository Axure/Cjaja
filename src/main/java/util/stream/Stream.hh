//
// Created by freet on 2017/7/9.
//

#ifndef CAPPA_STREAM_HH
#define CAPPA_STREAM_HH

#include <java/util/stream/BaseStream.hh>
#include <java/util/stream/StreamSupport.hh>
#include <java/util/stream/Streams.hh>
#include <java/util/Arrays.hh>

using java::util::stream::BaseStream;
namespace java {
namespace util {
namespace stream {

template<class T>
class Stream: public BaseStream<T, Stream<T>> {
 public:
  template<class R>
  static Stream<R> of(R t) {
//    return StreamSupport.stream(new Streams.StreamBuilderImpl<>(t), false);
  }

  /**
   * TODO: Use finer template checks.
   * @tparam R
   * @tparam TArgs
   * @param value
   * @param values
   * @return
   */
  template<class R, class ...TArgs>
  static Stream<R> of(R &value, TArgs... values) {
//    return Arrays.stream(value, values);
  }
};

}
}
}



#endif //CAPPA_STREAM_HH
