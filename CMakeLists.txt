cmake_minimum_required(VERSION 3.2)
project(cjaja)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES src/main/java/nio/Buffer.cc src/main/java/nio/Buffer.hh src/main/java/lang/Integer.cc src/main/java/lang/Integer.hh src/main/java/lang/String.cc src/main/java/lang/String.hh src/main/java/lang/Comparable.hh src/main/java/lang/System.cc src/main/java/lang/System.hh src/main/java/io/PrintStream.cc src/main/java/io/PrintStream.hh src/main/java/lang/Object.cc src/main/java/lang/Object.hh src/main/java/lang/AutoCloseable.hh src/main/java/io/Closeable.hh src/main/java/lang/Appendable.hh src/main/java/io/Flushable.hh src/main/java/lang/IOException.cc src/main/java/lang/IOException.hh src/main/java/io/Serializable.hh src/main/java/lang/Throwable.hh src/main/java/lang/Exception.cc src/main/java/lang/Exception.hh src/main/java/io/FilterOutputStream.cc src/main/java/io/FilterOutputStream.hh src/main/java/io/OutputStream.hh src/main/java/lang/CharSequence.cc src/main/java/lang/CharSequence.hh src/main/java/util/concurrent/ForkJoinPool.cc src/main/java/util/concurrent/ForkJoinPool.hh src/main/java/util/Collection.hh src/main/java/lang/Iterable.hh src/main/java/util/Iterator.hh src/main/java/util/function/Consumer.hh
        src/main/java/util/stream/Stream.hh
        src/main/java/util/stream/BaseStream.hh
        src/main/java/java.hh src/main/java/lang/StringIndexOutOfBoundsException.cc src/main/java/lang/StringIndexOutOfBoundsException.hh src/main/java/lang/IndexOutOfBoundsException.cc src/main/java/lang/IndexOutOfBoundsException.hh src/main/java/lang/RuntimeException.cc src/main/java/lang/RuntimeException.hh src/main/java/io/Writer.cc src/main/java/io/Writer.hh src/main/java/util/stream/Streams.cc src/main/java/util/stream/Streams.hh src/main/java/util/stream/StreamSupport.cc src/main/java/util/stream/StreamSupport.hh src/main/java/lang/Runnable.cc src/main/java/lang/Runnable.hh src/main/java/util/LinkedHashSet.cc src/main/java/util/LinkedHashSet.hh src/main/java/lang/Cloneable.cc src/main/java/lang/Cloneable.hh src/main/java/util/Set.hh src/main/java/util/AbstractCollection.hh src/main/java/util/AbstractSet.hh src/main/java/util/HashSet.hh src/main/java/util/Map.hh src/main/java/util/Arrays.cc src/main/java/util/Arrays.hh src/main/java/util/Scanner.cc src/main/java/util/Scanner.hh src/main/java/util/List.hh src/main/java/util/ArrayList.hh src/main/java/util/LinkedList.hh src/main/java/util/RandomAccess.hh src/main/java/util/AbstractList.hh src/main/java/util/Objects.cc src/main/java/util/Objects.hh src/main/java/util/stream/ReferencePipeline.hh src/main/java/util/stream/AbstractPipeline.hh src/main/java/util/stream/PipelineHelper.hh src/main/java/lang/Throwable.cc src/main/java/lang/Math.cc src/main/java/lang/Math.hh src/main/java/lang/Array.hh src/main/java/io/File.cc src/main/java/io/File.hh src/main/java/io/FileSystem.cc src/main/java/io/FileSystem.hh src/main/java/io/DefaultFileSystem.cc src/main/java/io/DefaultFileSystem.hh src/main/java/io/WinNTFileSystem.cc src/main/java/io/WinNTFileSystem.hh src/main/java/lang/Character.cc src/main/java/lang/Character.hh src/main/java/lang/NullPointerException.cc src/main/java/lang/NullPointerException.hh src/main/java/lang/StringBuffer.cc src/main/java/lang/StringBuffer.hh src/main/java/lang/AbstractStringBuilder.cc src/main/java/lang/AbstractStringBuilder.hh src/main/java/lang/Error.cc src/main/java/lang/Error.hh src/main/java/lang/VirtualMachineError.cc src/main/java/lang/VirtualMachineError.hh src/main/java/lang/OutOfMemoryError.cc src/main/java/lang/OutOfMemoryError.hh)
add_library(cppava ${SOURCE_FILES})
target_include_directories(cppava PRIVATE src/main)

# TODO: abstract the tests into a function.

add_executable(IntegerTest src/test/java/lang/IntegerTest.cc)
target_include_directories(IntegerTest PRIVATE src/main)
target_link_libraries(IntegerTest cppava)

add_executable(ObjectTest src/test/java/lang/ObjectTest.cc)
target_include_directories(ObjectTest PRIVATE src/main)
target_link_libraries(ObjectTest cppava)

add_executable(TimeTest src/test/java/time/TimeTest.cc)
target_include_directories(TimeTest PRIVATE src/main)
target_link_libraries(TimeTest cppava)

add_executable(StreamTest src/test/java/util/stream/StreamTest.cc)
target_include_directories(StreamTest PRIVATE src/main)
target_link_libraries(StreamTest cppava)

add_executable(FileTest src/test/java/io/FileTest.cc)
target_include_directories(FileTest PRIVATE src/main)
target_link_libraries(FileTest cppava)

add_executable(SytheticTest src/test/java/SytheticTest.cc)
target_include_directories(SytheticTest PRIVATE src/main)
target_link_libraries(SytheticTest cppava)

add_executable(IteratorTest src/test/java/util/IteratorTest.cc)
target_include_directories(IteratorTest PRIVATE src/main)
target_link_libraries(IteratorTest cppava)