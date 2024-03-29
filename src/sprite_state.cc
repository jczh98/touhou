/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include "sprite_state.h"

HorizontalFacing &operator++(HorizontalFacing &hf) {
  switch (hf) {
    case HorizontalFacing::LEFT : return hf = HorizontalFacing::RIGHT;
    case HorizontalFacing::RIGHT : return hf = HorizontalFacing::VERTICAL;
    case HorizontalFacing::VERTICAL: return hf = HorizontalFacing::LAST;
    case HorizontalFacing::LAST : return hf = HorizontalFacing::LEFT;
  }
  return hf;
}

