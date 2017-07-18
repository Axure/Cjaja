//
// Created by freet on 2017/7/7.
//

#include <cstdio>
#include <mutex>

#include "PrintStream.hh"

void java::io::PrintStream::print(int i) {
  printf("%d", i);
}


void java::io::PrintStream::println(int i) {
  {
//    std::unique_lock<Object> _lock(lock);
    printf("%d\n", i);
  }
}


void java::io::PrintStream::write(String &s) {

}

void java::io::PrintStream::write(String &&s) {

}

/**
 * TODO: not canonically implemented
 * @param s
 */
void java::io::PrintStream::print(String &s) {
  {
//     std::unique_lock<Object> _lock(lock);
//    char cbuf[];
//    if (len <= WRITE_BUFFER_SIZE) {
//      if (writeBuffer == null) {
//        writeBuffer = new char[WRITE_BUFFER_SIZE];
//      }
//      cbuf = writeBuffer;
//    } else {    // Don't permanently allocate very large buffers.
//      cbuf = new char[len];
//    }
//    str.getChars(off, (off + len), cbuf, 0);
//    write(cbuf, 0, len);
    char *buf = new char[s.length() + 1]();
    s.getChars(0, s.length(), buf, 0);
    printf("%s", buf);
    delete[] buf;
  }
}

void java::io::PrintStream::println(String &i) {
  print(i);
  print("\n");
}

/**
 *
 * TODO: not canonically implemented
 * @param i
 */
void java::io::PrintStream::print(String &&i) {
  char *buf = new char[i.length() + 1]();
  i.getChars(0, i.length(), buf, 0);
  printf("%s", buf);
  delete[] buf;
}

void java::io::PrintStream::println(String &&i) {
  print(i);
  print("\n");
}
