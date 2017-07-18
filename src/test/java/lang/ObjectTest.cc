//
// Created by freet on 2017/7/11.
//

#include <java/java.hh>
#include <string>

class TestClass {
 private:
  std::string name;
  char chars[5];

 public:
  char* getChar() {
    return this->chars;
  }
};

int main(int argc, char *argv[]) {
  TestClass testClass;

  Object mine;
  mine = testClass;

  Object yours(testClass);

  return 0;
}