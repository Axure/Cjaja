//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_DEFAULTFILESYSTEM_HH
#define CJAJA_DEFAULTFILESYSTEM_HH

#include <memory>
#include <java/java.hh>
#include <java/io/FileSystem.hh>
#include <java/io/WinNTFileSystem.hh>

namespace java {

namespace io {
class DefaultFileSystem {

 public:
  static std::shared_ptr<FileSystem> getFileSystem() {
    return std::make_shared<WinNTFileSystem>();
  }
};
}
}


#endif //CJAJA_DEFAULTFILESYSTEM_HH
