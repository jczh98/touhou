/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include "player.h"

const unsigned int kAnimationFps{15};

Player::Animation::Animation() :
    frame_timer_{std::chrono::milliseconds{1000 / kAnimationFps}},
    current_index_{0} {
}

void Player::Animation::Update() {
  if (frame_timer_.is_expired()) {
    frame_timer_.Reset();
    current_index_++;
    current_index_%=kAniNum;
  }
}

void Player::Animation::Reset() {
  current_index_ = 0;
  frame_timer_.Reset();
}

const int Player::Animation::current() const {
  return current_index_;
}
