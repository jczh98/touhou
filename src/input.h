/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_INPUT_H_
#define TOUHOU_SRC_INPUT_H_

#include <SDL.h>
#include <map>

struct Input {
  Input();

  void BeginNewFrame();

  void KeyDownEvent(const SDL_Event &event);
  void KeyUpEvent(const SDL_Event &event);

  bool WasKeyPressed(SDL_Scancode key);
  bool WasKeyReleased(SDL_Scancode key);
  bool IsKeyHeld(SDL_Scancode key);

 private:
  std::map<SDL_Scancode, bool> pressed_keys_;
  std::map<SDL_Scancode, bool> released_keys_;
  std::map<SDL_Scancode, bool> held_keys_;
};

#endif //TOUHOU_SRC_INPUT_H_
