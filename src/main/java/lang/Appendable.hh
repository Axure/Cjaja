//
// Created by freet on 2017/7/7.
//

#ifndef CPPAVA_APPENDABLE_HH
#define CPPAVA_APPENDABLE_HH

#include <java/java.hh>
#include <java/lang/CharSequence.hh>

using java::lang::CharSequence;

interface Appendable {
 public:
  virtual Appendable &append(CharSequence &csq) = 0;
  virtual Appendable &append(CharSequence &&csq) = 0;

  virtual Appendable &append(CharSequence &csq, int start, int end) = 0;
  virtual Appendable &append(CharSequence &&csq, int start, int end) = 0;

  virtual Appendable &append(char c) = 0;
};


#endif //CPPAVA_APPENDABLE_HH
