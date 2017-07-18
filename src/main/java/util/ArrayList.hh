//
// Created by freet on 2017/7/11.
//

#ifndef CJAJA_ARRAYLIST_HH
#define CJAJA_ARRAYLIST_HH

#include <java/java.hh>
#include <java/util/List.hh>
#include <java/util/AbstractList.hh>
#include <java/util/RandomAccess.hh>
#include <java/io/Serializable.hh>
#include <utility>
#include <typeinfo>
#include <cstdio>

namespace java {

namespace util {

template<class E>
class ArrayList
    : public AbstractList<E>,
      virtual public List<E>,
      virtual public RandomAccess,
      virtual public Cloneable,
      virtual public java::io::Serializable {


 private:
  static constexpr int DEFAULT_CAPACITY = 10;

//  static constexpr int MAX_ARRAY_SIZE = Integer.MAX_VALUE - 8;
  static constexpr int MAX_ARRAY_SIZE = 88888888 - 8;

 protected:
  int modCount = 0;

 private:
  int size_ = 0;

  Array<E> elementData = Array<E>(DEFAULT_CAPACITY);

 public:
  virtual ~ArrayList() {
    printf("destroying arraylist<%s>\n", typeid(E).name());
  }
 public:

  bool add(E &e) {
    ensureCapacityInternal(size_ + 1);  // Increments modCount!!
    elementData[size_++] = e;
    return true;
  }


  bool add(E &&e) {
    ensureCapacityInternal(size_ + 1);  // Increments modCount!!
    elementData[size_++] = e;
    return true;
  }

 private:
  void ensureCapacityInternal(int minCapacity) {
//    if (elementData == DEFAULTCAPACITY_EMPTY_ELEMENTDATA) {
    minCapacity = Math::max(DEFAULT_CAPACITY, minCapacity);
//    }
    ensureExplicitCapacity(minCapacity);
  }

  void ensureExplicitCapacity(int minCapacity) {
    modCount++;

//    elementData = Array<E>(DEFAULT_CAPACITY);
    printf("size of elementData is %d\n", elementData.length);
    // overflow-conscious code
    if (minCapacity - elementData.length > 0)
      grow(minCapacity);
  }

  void grow(int minCapacity) {
    printf("Growing from %d to %d\n", this->size_, minCapacity);
    // overflow-conscious code
    int oldCapacity = elementData.length;
    int newCapacity = oldCapacity + (oldCapacity >> 1);
    if (newCapacity - minCapacity < 0)
      newCapacity = minCapacity;
    if (newCapacity - MAX_ARRAY_SIZE > 0)
      newCapacity = hugeCapacity(minCapacity);
    // minCapacity is usually close to size, so this is a win:
    elementData = Arrays::copyOf(elementData, newCapacity);
  }

  static int hugeCapacity(int minCapacity) {
    if (minCapacity < 0) // overflow
      throw 1;
//      throw new OutOfMemoryError();
    return (minCapacity > MAX_ARRAY_SIZE) ?
           88888888 :
           MAX_ARRAY_SIZE;
  }


 public:
  Iterator<E> &&iterator2() override {
    return std::move<Iterator<E>>(Itr(*this));
  }

  std::shared_ptr<Iterator<E>> iterator() override {
    return std::make_shared<Itr>((*this));
  }

  Iterator<E> &&begin() override {
    return std::move<Iterator<E>>(this->iterator2());
  }

  Iterator<E> &&end() override {
    return std::move<Iterator<E>>(Itr(*this, true));
  }

  int size() override {
    return this->size_;
  }

  bool isEmpty() override {
    return this->size_ == 0;
  }

 public:
  class Itr: public Iterator<E> {
   private:
    ArrayList &arrayList;

    // index of next element to return
    int lastRet = -1; // index of last element returned; -1 if no such
    int expectedModCount = arrayList.modCount;

   public:
    Itr(ArrayList &arrayList, bool end = false) : arrayList(arrayList) {
      if (end) {
        this->cursor = arrayList.size_ - 1;
      } else {
        this->cursor = 0;
      }
      printf("cursor is %d, addr is %p\n", this->cursor, &(this->cursor));
    }

    ~Itr() {
      System::out.println("Destroed");
    }


    Itr(Iterator<E> &&iterator) : arrayList(((Itr &&) iterator).arrayList) {
      System::out.println("rvalue constructed");
      this->cursor = ((Itr &&) iterator).cursor;
      printf("obj is %p\n", &((Itr &) iterator));
      printf("cursor is %d, addr is %p\n", ((Itr &&) iterator).cursor, &(((Itr &) iterator).cursor));

//      System::out.println(this->arrayList.size_);
    }

    void operator=(Iterator<E> &&iterator) {
      System::out.println("rvalue assigned");
      this->arrayList = (((Itr &&) iterator).arrayList);
      this->cursor = ((Itr &&) iterator).cursor;
    }

   public:
//    bool operator!=(const Iterator<E> &other) override {
//      return this->cursor != other.cursor;
//    }

//    E operator*() override {
//      checkForComodification();
//      int i = this->cursor;
//      if (i >= arrayList.size_)
//        throw 3;
////        throw new NoSuchElementException();
////      Object[] elementData = ArrayList.this.elementData;
//      if (i >= length(arrayList.elementData))
//        throw 4;
////        throw new ConcurrentModificationException();
//      return *arrayList.elementData[lastRet = i];
//    }

//    Iterator<E> &operator++() override {
//      this->cursor += 1;
//      return *this;
//    }

    bool hasNext() override {
      return this->cursor != arrayList.size_;
    }

    E next() override {
//      checkForComodification();
      int i = this->cursor;
      printf("size %d\n", arrayList.size_);
      if (i >= arrayList.size_) {
        printf("%d >= %d\n", i, arrayList.size_);
        throw String("Bad bad");
      }
//        throw new NoSuchElementException();
//      Object[] elementData = ArrayList.this.elementData;
      printf("length: %d\n", (arrayList.elementData.length));
//      if (i >= length(arrayList.elementData))
//        throw 4;
//        throw new ConcurrentModificationException();
      this->cursor = i + 1;
      return arrayList.elementData[lastRet = i];
//      return *arrayList.elementData[lastRet = 0];
    }

    void checkForComodification() {
      if (arrayList.modCount != expectedModCount)
//        throw new ConcurrentModificationException();
        throw 2;
    }
  };

};
}
}

#endif //CJAJA_ARRAYLIST_HH
