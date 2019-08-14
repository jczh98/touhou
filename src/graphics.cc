/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */
#include <stdexcept>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "game.h"

Graphics::Graphics() :
    sdl_window_{SDL_CreateWindow(
        "touhou",
        SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        Game::kScreenWidth,
        Game::kScreenHeight,
        SDL_WINDOW_SHOWN
    )},
    sdl_renderer_{SDL_CreateRenderer(
        sdl_window_,
        -1,
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_TARGETTEXTURE
    )},
    sprite_sheets_() {
  if (sdl_window_ == nullptr) {
    throw std::runtime_error("SDL_CreateWindow");
  }
  if (sdl_renderer_ == nullptr) {
    throw std::runtime_error("SDL_CreateRenderer");
  }
  SDL_RenderSetLogicalSize(sdl_renderer_, Game::kScreenWidth, Game::kScreenHeight);
}

Graphics::~Graphics() {
  for (auto &kv : sprite_sheets_) {
    SDL_DestroyTexture(kv.second);
  }
  SDL_DestroyRenderer(sdl_renderer_);
  SDL_DestroyWindow(sdl_window_);
}

SDL_Texture *Graphics::LoadImage(const std::string &path, const bool black_is_transparent) {
  if (sprite_sheets_.count(path) == 0) {
    SDL_Texture *texture;
    if (black_is_transparent) {
      SDL_Surface *surface = SDL_LoadBMP(path.c_str());
      if (surface == nullptr) {
        const auto warn_str = "Cannot load texture '" + path + "'!";
        throw std::runtime_error(warn_str);
      }
      const Uint32 black_color = SDL_MapRGB(surface->format, 0, 0, 0);
      SDL_SetColorKey(surface, SDL_TRUE, black_color);
      texture = SDL_CreateTextureFromSurface(sdl_renderer_, surface);
      SDL_FreeSurface(surface);
    } else {
      texture = IMG_LoadTexture(sdl_renderer_, path.c_str());
    }
    if (texture == nullptr) {
      throw std::runtime_error("Cannot load texture.");
    }
    sprite_sheets_[path] = texture;
  }
  return sprite_sheets_[path];
}

void Graphics::RenderTexture(SDL_Texture *texture, const SDL_Rect dst, const SDL_Rect *clip) const {
  SDL_RenderCopy(sdl_renderer_, texture, clip, &dst);
}

void Graphics::RenderTexture(SDL_Texture *texture, const int x, const int y, const SDL_Rect *clip) const {
  SDL_Rect dst;
  dst.x = x;
  dst.y = y;
  if (clip != nullptr) {
    dst.w = clip->w;
    dst.h = clip->h;
  } else {
    SDL_QueryTexture(texture, nullptr, nullptr, &dst.w, &dst.h);
  }
  RenderTexture(texture, dst, clip);
}
void Graphics::flip() const {
  SDL_RenderPresent(sdl_renderer_);
}

void Graphics::clear() const {
  SDL_RenderClear(sdl_renderer_);
}
