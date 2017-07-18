#include <java/lang/Integer.hh>
#include <java/lang/System.hh>

using java::lang::Integer;
using java::lang::System;

int main(int argc, char *argv[]) {
  auto integer_1 = Integer(1);
  auto integer_2 = Integer(2);

  System::out.print(integer_1.compareTo(integer_2));

  String a("hehe");
  System::out.print("\n");
  System::out.print(a);
}