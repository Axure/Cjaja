//
// Created by freet on 2017/7/17.
//

#ifndef CJAJA_WINNTFILESYSTEM_HH
#define CJAJA_WINNTFILESYSTEM_HH

#include <java/java.hh>
#include <java/io/FileSystem.hh>
#include <java/lang/StringBuffer.hh>

namespace java {

namespace io {
class WinNTFileSystem: public FileSystem {
 public:
  WinNTFileSystem();

 public:
  bool createFileExclusively(const String &pathname) const override;

  int getBooleanAttributes(File &f) const override;

  String normalize(String path) const override;


  int prefixLength(String path) const override;

 private:
  boolean isSlash(char c) const;
  boolean isLetter(char c) const;
  String normalize(String path, int len, int off) const;

  int normalizePrefix(String path, int len, StringBuffer &sb) const;
 private:
  char slash = '\\'; /** not fully implemented */
  char altSlash = '/'; /** not fully implemented */
  char semicolon = ';'; /** not fully implemented */
};
}
}

#endif //CJAJA_WINNTFILESYSTEM_HH
