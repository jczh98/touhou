/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include "input.h"

Input::Input() :
    held_keys_(),
    pressed_keys_(),
    released_keys_() {

}

void Input::BeginNewFrame() {
  pressed_keys_.clear();
  released_keys_.clear();
}

void Input::KeyDownEvent(const SDL_Event &event) {
  pressed_keys_[event.key.keysym.scancode] = true;
  held_keys_[event.key.keysym.scancode] = true;
}

void Input::KeyUpEvent(const SDL_Event &event) {
  released_keys_[event.key.keysym.scancode] = true;
  held_keys_[event.key.keysym.scancode] = false;
}

bool Input::WasKeyPressed(SDL_Scancode key) {
  return pressed_keys_[key];
}

bool Input::WasKeyReleased(SDL_Scancode key) {
  return released_keys_[key];
}

bool Input::IsKeyHeld(SDL_Scancode key) {
  return held_keys_[key];
}
