//
// Created by freet on 2017/7/11.
//
#include <java/java.hh>
#include <java/util/Collection.hh>
#include <java/util/ArrayList.hh>
#include <java/util/Iterator.hh>

using java::util::Collection;
using java::util::ArrayList;
using java::util::Iterator;
//template<class T>
//inline int length(T arr[]) {
//  return sizeof(arr) / sizeof(T);
//}


class Main {

//  String arr[7]{"1", "2", "3", "4", "5", "6", "7"};


 public:
  void method1() {

    auto arr = Array<String> {"1", "2", "3", "4", "5", "6", "7"};
    int count = 0;
    for (int i = 0; i < arr.length; i++) {
      for (int j1 = i + 1; j1 < arr.length; j1++) {
        for (int j2 = j1 + 1; j2 < arr.length; j2++) {
          for (int j3 = j2 + 1; j3 < arr.length; j3++) {
            for (int j4 = j3 + 1; j4 < arr.length; j4++) {
              count++;
              System::out.println(arr[i] + " " + arr[j1] + " " + arr[j2] + " " + arr[j3] + " " + arr[j4]);
            }
          }
        }
      }
    }
    System::out.println(count);

  }

  void method2() {

    int count = 0;
    int level = 0;
    const int MAX_LEVEL = 5;

//        for

    System::out.println(count);
  }

  void recursion(int level, int maxLevel) {

  }

  class Person {
   private:
    String First_name;

   private:
    String Last_name;

   private:
    String Country;

   public:
    Person() {

    }

    void operator=(Person &another) {

      First_name = another.First_name;
      Last_name = another.Last_name;
      Country = another.Country;
    }


    Person(String first_name, String last_name, String country) {
      First_name = first_name;
      Last_name = last_name;
      Country = country;
    }

    Person(Person &person) : First_name(person.First_name), Last_name(person.Last_name), Country(person.Country) {
      System::out.println("Copy ctor called");
    }

    Person(Person &&person) : First_name(person.First_name), Last_name(person.Last_name), Country(person.Country) {
      System::out.println("Move ctor called");
    }

   public:
    String getFirst_name() {
      return First_name;
    }

   public:
    void setFirst_name(String first_name) {
      First_name = first_name;
    }

   public:
    String getLast_name() {
      return Last_name;
    }

   public:
    void setLast_name(String last_name) {
      Last_name = last_name;
    }

   public:
    String getCountry() {
      return Country;
    }

   public:
    void setCountry(String country) {
      Country = country;
    }
  };

  void spliterator() {
    // Create a new Collection type; in this case an ArrayList
//    auto people_ = ArrayList<Person>();
    auto people = ArrayList<Person>();
//// Add some people using Person objects
    people.add(Person("Jane", "Doe", "Ireland"));
    System::out.println(people.size());
    people.add(Person("Joe", "Doe", "England"));
    System::out.println(people.size());
    people.add(Person("John", "Doe", "Scotland"));
    System::out.println(people.size());
    people.add(Person("Julie", "Doe", "Wales"));
    System::out.println(people.size());
    people.add(Person("Jerry", "Doe", "France"));
    System::out.println(people.size());
    people.add(Person("Jim", "Doe", "Italy"));
    System::out.println(people.size());

//// simple iterator example
    auto peopleIterator = people.iterator();
    auto peopleIterator2 = people.iterator();
//
////    Person person = peopleIterator.next();

    System::out.println(people.size());

    Person person2 = peopleIterator2->next();

    System::out.println("Hello " + person2.getFirst_name() +
        " " + person2.getLast_name() +
        " from " + person2.getCountry());

    Array<int> array(5);
    array[3] = 2;
    System::out.println(array[3]);

    while (peopleIterator->hasNext()) {
      Person person = peopleIterator->next();
      System::out.println("Hello " + person.getFirst_name() +
          " " + person.getLast_name() +
          " from " + person.getCountry());
    }

  }

};

int main() {

  Main main;
  main.method1();
  main.method2();
  main.spliterator();
}