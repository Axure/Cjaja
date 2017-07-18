//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_FILE_HH
#define CJAJA_FILE_HH

#include <java/java.hh>
#include <java/io/FileSystem.hh>

namespace java {

namespace io {

class FileSystem;

class File: public Serializable, public Comparable<File> {
 private:
  enum PathStatus { INVALID, CHECKED };
 private:
  transient PathStatus status;

  String path;

  transient int prefixLength;

  static const FileSystem *fs;

 public:
  File(String &pathname);

  int compareTo(File &o) override;

  int compareTo(File &&o) override;

 public:
  boolean exists();

  boolean createNewFile();

 protected:
  const boolean isInvalid();
};
}
}


#endif //CJAJA_FILE_HH
