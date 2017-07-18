//
// Created by freet on 2017/7/11.
//

#ifndef CJAJA_MATH_HH
#define CJAJA_MATH_HH


class Math {
 public:
  static int max(int a, int b) {
    return (a >= b) ? a : b;
  }

  static long max(long a, long b) {
    return (a >= b) ? a : b;
  }

 public:
  static int min(int a, int b) {
    return (a <= b) ? a : b;
  }

 public:
  static double abs(double a) {
    return (a <= 0.0D) ? 0.0D - a : a;
  }

  static float abs(float a) {
    return (a <= 0.0F) ? 0.0F - a : a;
  }

  static long abs(long a) {
    return (a < 0) ? -a : a;
  }

  static int abs(int a) {
    return (a < 0) ? -a : a;
  }
};


#endif //CJAJA_MATH_HH
