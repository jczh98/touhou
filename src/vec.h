/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_VEC_H_
#define TOUHOU_SRC_VEC_H_

template<typename T>
struct Vec {
  T x, y;
  Vec<T> operator+(const Vec<T> &rhs) const {
    return Vec{x + rhs.x, y + rhs.y};
  }
};

#endif //TOUHOU_SRC_VEC_H_
