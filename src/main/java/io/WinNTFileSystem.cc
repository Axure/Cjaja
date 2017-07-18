//
// Created by freet on 2017/7/17.
//

#include "WinNTFileSystem.hh"

//#include <windows.h>
//
//BOOL DirectoryExists(LPCTSTR szPath)
//{
//  DWORD dwAttrib = GetFileAttributes(szPath);
//
//  return (dwAttrib != INVALID_FILE_ATTRIBUTES &&
//      (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
//}
//
//void createDirectoryRecursively(std::wstring path)
//{
//  unsigned int pos = 0;
//  do
//  {
//    pos = path.find_first_of(L"\\/", pos + 1);
//    CreateDirectory(path.substr(0, pos).c_str(), NULL);
//  } while (pos != std::string::npos);
//}

bool java::io::WinNTFileSystem::createFileExclusively(const String &pathname) const {
  return false;
}

int java::io::WinNTFileSystem::getBooleanAttributes(java::io::File &f) const {
  return 0;
}

String java::io::WinNTFileSystem::normalize(String path) const {
  int n = path.length();
  char slash = this->slash;
  char altSlash = this->altSlash;
  char prev = 0;
  for (int i = 0; i < n; i++) {
    char c = path.charAt(i);
    if (c == altSlash)
      return normalize(path, n, (prev == slash) ? i - 1 : i);
    if ((c == slash) && (prev == slash) && (i > 1))
      return normalize(path, n, i - 1);
    if ((c == ':') && (i > 1))
      return normalize(path, n, 0);
    prev = c;
  }
  if (prev == slash) return normalize(path, n, n - 1);
  return path;
}

int java::io::WinNTFileSystem::prefixLength(String path) const {
  char slash = this->slash;
  int n = path.length();
  if (n == 0) return 0;
  char c0 = path.charAt(0);
  char c1 = (n > 1) ? path.charAt(1) : 0;
  if (c0 == slash) {
    if (c1 == slash) return 2;  /* Absolute UNC pathname "\\\\foo" */
    return 1;                   /* Drive-relative "\\foo" */
  }
  if (isLetter(c0) && (c1 == ':')) {
    if ((n > 2) && (path.charAt(2) == slash))
      return 3;               /* Absolute local pathname "z:\\foo" */
    return 2;                   /* Directory-relative "z:foo" */
  }
  return 0;                       /* Completely relative */
}

boolean java::io::WinNTFileSystem::isSlash(char c) const {
  return (c == '\\') || (c == '/');
}

int java::io::WinNTFileSystem::normalizePrefix(String path, int len, StringBuffer &sb) const {
  int src = 0;
  while ((src < len) && isSlash(path.charAt(src))) src++;
  char c;
  if ((len - src >= 2)
      && isLetter(c = path.charAt(src))
      && path.charAt(src + 1) == ':') {
    /* Remove leading slashes if followed by drive specifier.
       This hack is necessary to support file URLs containing drive
       specifiers (e.g., "file://c:/path").  As a side effect,
       "/c:/path" can be used as an alternative to "c:/path". */
    sb.append(c);
    sb.append(':');
    src += 2;
  } else {
    src = 0;
    if ((len >= 2)
        && isSlash(path.charAt(0))
        && isSlash(path.charAt(1))) {
      /* UNC pathname: Retain first slash; leave src pointed at
         second slash so that further slashes will be collapsed
         into the second slash.  The result will be a pathname
         beginning with "\\\\" followed (most likely) by a host
         name. */
      src = 1;
      sb.append(slash);
    }
  }
  return src;
}

String java::io::WinNTFileSystem::normalize(String path, int len, int off) const {
  if (len == 0) return path;
  if (off < 3) off = 0;   /* Avoid fencepost cases with UNC pathnames */
  int src;
  char slash = this->slash;

  StringBuffer sb (len);

  if (off == 0) {
    /* Complete normalization, including prefix */
    src = normalizePrefix(path, len, sb);
  } else {
    /* Partial normalization */
    src = off;
    sb.append(path.substring(0, off));
  }

  /* Remove redundant slashes from the remainder of the path, forcing all
     slashes into the preferred slash */
  while (src < len) {
    char c = path.charAt(src++);
    if (isSlash(c)) {
      while ((src < len) && isSlash(path.charAt(src))) src++;
      if (src == len) {
        /* Check for trailing separator */
        int sn = sb.length();
        if ((sn == 2) && (sb.charAt(1) == ':')) {
          /* "z:\\" */
          sb.append(slash);
          break;
        }
        if (sn == 0) {
          /* "\\" */
          sb.append(slash);
          break;
        }
        if ((sn == 1) && (isSlash(sb.charAt(0)))) {
          /* "\\\\" is not collapsed to "\\" because "\\\\" marks
             the beginning of a UNC pathname.  Even though it is
             not, by itself, a valid UNC pathname, we leave it as
             is in order to be consistent with the win32 APIs,
             which treat this case as an invalid UNC pathname
             rather than as an alias for the root directory of
             the current drive. */
          sb.append(slash);
          break;
        }
        /* Path does not denote a root directory, so do not append
           trailing slash */
        break;
      } else {
        sb.append(slash);
      }
    } else {
      sb.append(c);
    }
  }

  String rv = sb.toString();
  return rv;
}

boolean java::io::WinNTFileSystem::isLetter(char c) const {
  return ((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z'));
}

java::io::WinNTFileSystem::WinNTFileSystem() {

}
