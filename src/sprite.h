/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_SPRITE_H_
#define TOUHOU_SRC_SPRITE_H_

#include "graphics.h"
#include "vec.h"

struct Sprite {
  Sprite(Graphics &graphics,
         const std::string &path,
         int x, int y,
         int width, int height);
  virtual ~Sprite() = default;

  Sprite(const Sprite &) = delete;
  Sprite &operator=(const Sprite &) = delete;

  virtual void Update() {}

  void Draw(Graphics &graphics, const Vec<double> &pos) const;

 private:
  SDL_Texture *texture_;

 protected:
  SDL_Rect rect_;
};

#endif //TOUHOU_SRC_SPRITE_H_
