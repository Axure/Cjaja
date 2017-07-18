#include <java/java.hh>
#include <java/util/stream/Stream.hh>
#include <java/lang/System.hh>

using java::lang::System;
using java::util::stream::Stream;

int main(int argc, char *argv[]) {
  Stream.of("d2", "a2", "b1", "b3", "c")
      .filter([](auto &s) {
        System::out.println("filter: " + s);
        return true;
      })
      .forEach([](auto &s) { System::out.println("forEach: " + s); });

  Integer sixNums[] = {1, 2, 3, 4, 5, 6};
  Integer evens[] =
                Stream.of(sixNums).filter([](auto &n) { return  n%2 == 0; }).toArray(Integer[]::new);
}