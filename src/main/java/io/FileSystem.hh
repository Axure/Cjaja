//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_FILESYSTEM_HH
#define CJAJA_FILESYSTEM_HH

#include <java/java.hh>

namespace java {

namespace io {
class File;

class FileSystem {
 public:
  /* Constants for simple boolean attributes */
  static const int BA_EXISTS = 0x01;

  static const int BA_REGULAR = 0x02;

  static const int BA_DIRECTORY = 0x04;

  static const int BA_HIDDEN = 0x08;

 public:
  virtual boolean createFileExclusively(const String &pathname) const = 0;

  /**
   * Return the simple boolean attributes for the file or directory denoted
   * by the given abstract pathname, or zero if it does not exist or some
   * other I/O error occurs.
   */
  virtual int getBooleanAttributes(File &f) const = 0;

  virtual String normalize(String path) const = 0;

  virtual int prefixLength(String path) const = 0;
};
}
}


#endif //CJAJA_FILESYSTEM_HH
