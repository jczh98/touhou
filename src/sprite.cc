/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include "sprite.h"

Sprite::Sprite(Graphics &graphics,
               const std::string &path,
               const int x,
               const int y,
               const int width,
               const int height) :
    texture_{graphics.LoadImage(path, false)},
    rect_{x, y, width, height} {

}

void Sprite::Draw(Graphics &graphics, const Vec<double> &pos) const {
  const int dstx = round(pos.x);
  const int dsty = round(pos.y);

  graphics.RenderTexture(texture_, dstx, dsty, &rect_);
}

