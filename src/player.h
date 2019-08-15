/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_PLAYER_H_
#define TOUHOU_SRC_PLAYER_H_

#include <chrono>
#include "graphics.h"
#include "vec.h"
#include "sprite_state.h"
#include "sprite.h"
#include "timer.h"

struct Player {
  Player(Graphics &graphics, Vec<double> pos);
  ~Player();

  void Update(const std::chrono::milliseconds elapsed_time);
  void Draw(Graphics &graphics) const;

  void StartMovingLeft();
  void StartMovingRight();
  void StartMovingUp();
  void StartMovingDown();
  void StopMovingHorizontal();
  void StopMovingVertical();

  void StartFire();
  void StopFire();

  const Vec<double> center_pos() const;
  const double speed() const;

  static const int kAniNum{8};

 private:
  struct SpriteState {
    SpriteState(HorizontalFacing horizontal_facing = HorizontalFacing::VERTICAL,
                int current_frame_index = 0) :
        horizontal_facing{horizontal_facing},
        current_frame_index{current_frame_index} {}

    auto rank() const;
    HorizontalFacing horizontal_facing;
    int current_frame_index;
    VerticalFacing vertical_facing;
  };

  friend bool operator<(const SpriteState &a, const SpriteState &b);

  struct Animation {
    Animation();
    void Update();
    void Reset();
    const int current() const;
   private:
    Timer frame_timer_;
    int current_index_;
  };

  void InitializeSprites(Graphics &graphics);
  void InitializeSprite(Graphics &graphics, SpriteState sprite_state);

  inline unsigned int GetFrameX(const SpriteState &sprite_state) const;
  inline unsigned int GetFrameY(const SpriteState &sprite_state) const;
  inline const SpriteState sprite_state() const;

  HorizontalFacing horizontal_facing_;
  VerticalFacing vertical_facing_;
  Animation animation_;
  int current_frame_index_;
  double speed_;
  Vec<double> pos_;
  std::map<SpriteState, std::unique_ptr<Sprite>> sprites_;
};

#endif //TOUHOU_SRC_PLAYER_H_
