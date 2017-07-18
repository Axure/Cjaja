//
// Created by freet on 2017/7/17.
//

#include "Character.hh"

boolean Character::isValidCodePoint(int codePoint) {
  // Optimized form of:
  //     codePoint >= MIN_CODE_POINT && codePoint <= MAX_CODE_POINT
  int plane = (uint32_t)codePoint >> 16;
  return plane < (uint8_t)((MAX_CODE_POINT + 1) >> 16);
}

char Character::highSurrogate(int codePoint) {
  return (char) (((uint32_t)codePoint >> 10)
      + (MIN_HIGH_SURROGATE - ((uint8_t)MIN_SUPPLEMENTARY_CODE_POINT >> 10)));
}

char Character::lowSurrogate(int codePoint) {
  return (char) ((codePoint & 0x3ff) + MIN_LOW_SURROGATE);
}
