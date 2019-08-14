/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_SDL_ENGINE_H_
#define TOUHOU_SRC_SDL_ENGINE_H_

#include <SDL.h>

struct SDLEngine {

  SDLEngine() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
      throw std::runtime_error("SDL_Init");
    }
  }

  ~SDLEngine() {
    SDL_Quit();
  }
};

#endif //TOUHOU_SRC_SDL_ENGINE_H_
