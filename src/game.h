//
// Created by Chin Zhou on 2019-08-13.
//

#ifndef TOUHOU_GAME_H
#define TOUHOU_GAME_H

#include <string>
#include <chrono>
#include <stdexcept>
#include <SDL.h>
#include <SDL_image.h>
#include "graphics.h"
#include "sdl_engine.h"
#include "player.h"
struct Game {
  Game();
  ~Game();
  static int kScreenHeight;
  static int kScreenWidth;
 private:
  void RunEventLoop();
  void Update(std::chrono::milliseconds elapsed_time,
              Graphics &graphics);
  void Draw(Graphics &graphics) const;

  SDLEngine sdl_engine_;
  Graphics graphics_;

  std::shared_ptr<Player> player_;
};
#endif //TOUHOU_GAME_H
