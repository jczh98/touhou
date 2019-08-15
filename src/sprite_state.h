/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_SPRITE_STATE_H_
#define TOUHOU_SRC_SPRITE_STATE_H_

enum class HorizontalFacing {
  FIRST,
  LEFT = FIRST,
  VERTICAL,
  RIGHT,
  LAST
};

HorizontalFacing &operator++(HorizontalFacing &hf);

enum class VerticalFacing {
  FIRST,
  UP = FIRST,
  DOWN,
  LAST
};

VerticalFacing &operator++(VerticalFacing &vf);

#endif //TOUHOU_SRC_SPRITE_STATE_H_
