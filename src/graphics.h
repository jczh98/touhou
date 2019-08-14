/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_GRAPHICS_H_
#define TOUHOU_SRC_GRAPHICS_H_

#include <SDL.h>
#include <string>
#include <map>

struct Graphics {
  Graphics();
  ~Graphics();

  Graphics(const Graphics &) = delete;
  Graphics &operator=(const Graphics &) = delete;

  SDL_Texture *LoadImage(const std::string &path,
                         const bool black_is_transparent = false);

  void RenderTexture(SDL_Texture *texture,
                     const SDL_Rect dst,
                     const SDL_Rect *clip = nullptr) const;
  void RenderTexture(SDL_Texture *texture,
                     const int x, const int y,
                     const SDL_Rect *clip = nullptr) const;
  void flip() const;
  void clear() const;

 private:
  SDL_Window *sdl_window_;
  SDL_Renderer *sdl_renderer_;
  std::map<std::string, SDL_Texture *> sprite_sheets_;
};

#endif //TOUHOU_SRC_GRAPHICS_H_
