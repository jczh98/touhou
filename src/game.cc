//
// Created by Chin Zhou on 2019-08-13.
//

#include <iostream>
#include "game.h"
#include "input.h"
#include "timer.h"
#include "sprite.h"

const unsigned int kFps = 60;
const auto kMaxFrameTime = std::chrono::milliseconds{5 * 1000 / 60};
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 480;

Game::Game() :
    sdl_engine_(),
    graphics_() {
  RunEventLoop();
}

Game::~Game() = default;

void Game::RunEventLoop() {
  Input input;
  SDL_Event event;
  bool running = true;
  auto last_updated_time = std::chrono::high_resolution_clock::now();
  while (running) {
    const auto start_time = std::chrono::high_resolution_clock::now();

    input.BeginNewFrame();
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
        case SDL_KEYDOWN:input.KeyDownEvent(event);
          break;
        case SDL_KEYUP:input.KeyUpEvent(event);
          break;
        case SDL_QUIT:running = false;
          break;
        default:break;
      }
    }
    // Player movement

    // Update scene and last updated time
    const auto current_time = std::chrono::high_resolution_clock::now();
    const auto updated_elapsed_time = current_time - last_updated_time;

    Update(std::min(
        std::chrono::duration_cast<std::chrono::milliseconds>(updated_elapsed_time),
        kMaxFrameTime),
           graphics_);
    last_updated_time = current_time;
    Draw(graphics_);

    // Calculate delay for constant fps
    const auto end_time = std::chrono::high_resolution_clock::now();
    const auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
    const auto delay_duration = std::chrono::milliseconds(1000) / kFps - elapsed_time;
    if (delay_duration.count() >= 0) {
      SDL_Delay(delay_duration.count());
    }
  }
}

void Game::Update(const std::chrono::milliseconds elapsed_time, Graphics &graphics) {
  Timer::UpdateAll(elapsed_time);
}

void Game::Draw(Graphics &graphics) const {
  graphics.clear();
  graphics.flip();
}
