//
// Created by freet on 2017/7/7.
//

#include "Object.hh"

java::lang::Object::~Object() {
  if (this->storage != nullptr) delete this->storage;
}

java::lang::Object::Object() {

}
