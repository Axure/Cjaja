#include <java/java.hh>
#include <java/io/File.hh>

using java::io::File;

boolean createFile(String filePath) {
  boolean result = false;
//  File file = new File(filePath);
  auto file = new File(filePath);

  if (!file->exists()) {
    try {
      result = file->createNewFile();
    } catch (IOException &e) {
      e.printStackTrace();
    }
  }

  delete file;

  return result;
}

int main(int argc, char *argv[]) {
  createFile("hehe.res");
}