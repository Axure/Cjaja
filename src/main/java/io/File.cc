//
// Created by freet on 2017/7/17.
//

#include "File.hh"

#include <java/io/FileSystem.hh>
#include <java/io/DefaultFileSystem.hh>

using java::io::FileSystem;
using java::io::DefaultFileSystem;
const FileSystem *java::io::File::fs = DefaultFileSystem::getFileSystem().get();

bool java::io::File::exists() {
//  SecurityManager security = System.getSecurityManager();
//  if (security != null) {
//    security.checkRead(path);
//  }
  if (isInvalid()) {
    return false;
  }
  return ((fs->getBooleanAttributes(*this) & FileSystem::BA_EXISTS) != 0);
}

const boolean java::io::File::isInvalid() {
  if (status == null) {
    status = (this->path.indexOf('\u0000') < 0) ? PathStatus::CHECKED
                                                : PathStatus::INVALID;
  }
  return status == PathStatus::INVALID;
}

boolean java::io::File::createNewFile() {
//  SecurityManager security = System.getSecurityManager();
//  if (security != null) security.checkWrite(path);
  if (isInvalid()) {
    throw new IOException("Invalid file path");
  }
  return fs->createFileExclusively(path);
}

int java::io::File::compareTo(java::io::File &o) {
  return 0; /** @unimplemented */
}

int java::io::File::compareTo(java::io::File &&o) {
  return 0; /** @unimplemented */
}

java::io::File::File(String &pathname) {

//  if (pathname == null) { /** TODO： consider using `nullptr` for comparison. */
//    throw new NullPointerException();
//  }
  this->path = fs->normalize(pathname);
  this->prefixLength = fs->prefixLength(this->path);
}
