/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include <iostream>
#include "player.h"

// Sprite
const std::string kPlayerSpriteFilePath{"res/textures/player/pl00/pl00.png"};
const int kPlayerWidth{32};
const int kPlayerHeight{48};

Player::Player(Graphics &graphics, Vec<double> pos) :
    pos_{pos},
    horizontal_facing_{HorizontalFacing::VERTICAL},
    vertical_facing_{VerticalFacing::STAY},
    current_frame_index_{0},
    speed_{10.0},
    animation_(),
    sprites_() {
  InitializeSprites(graphics);
}

Player::~Player() {

}

void Player::Update(const std::chrono::milliseconds elapsed_time) {
  sprites_[sprite_state()]->Update();
  animation_.Update();

  // Update positions
  if (horizontal_facing_ == HorizontalFacing::RIGHT) {
    pos_.x += speed();
  } else if (horizontal_facing_ == HorizontalFacing::LEFT) {
    pos_.x -= speed();
  }

  if (vertical_facing_ == VerticalFacing::UP) {
    pos_.y -= speed();
  } else if (vertical_facing_ == VerticalFacing::DOWN) {
    pos_.y += speed();
  }

}

void Player::Draw(Graphics &graphics) const {
  sprites_.at(sprite_state())->Draw(graphics, pos_);
}

void Player::StartMovingLeft() {
  horizontal_facing_ = HorizontalFacing::LEFT;
}

void Player::StartMovingRight() {
  horizontal_facing_ = HorizontalFacing::RIGHT;
}

void Player::StopMovingHorizontal() {
  horizontal_facing_ = HorizontalFacing::VERTICAL;
}

void Player::StartMovingUp() {
  vertical_facing_ = VerticalFacing::UP;
}

void Player::StartMovingDown() {
  vertical_facing_ = VerticalFacing::DOWN;
}

void Player::StopMovingVertical() {
  vertical_facing_ = VerticalFacing::STAY;
}

void Player::StartFire() {

}
void Player::StopFire() {

}

auto Player::SpriteState::rank() const {
  return std::tie(horizontal_facing, current_frame_index);
}

bool operator<(const Player::SpriteState &a, const Player::SpriteState &b) {
  return a.rank() < b.rank();
}

const Vec<double> Player::center_pos() const {
  return Vec<double>{
      pos_.x,
      pos_.y
  };
}

void Player::InitializeSprites(Graphics &graphics) {
  for (auto hf = HorizontalFacing::FIRST; hf != HorizontalFacing::LAST; ++hf) {
    for (int frame = 0; frame < kAniNum; ++frame) {
      auto sprite_state = SpriteState(hf, frame);
      InitializeSprite(graphics, sprite_state);
    }
  }
}

void Player::InitializeSprite(Graphics &graphics, Player::SpriteState sprite_state) {
  unsigned int frame_x = GetFrameX(sprite_state);
  unsigned int frame_y = GetFrameY(sprite_state);
  sprites_[sprite_state] = std::make_unique<Sprite>(
      graphics,
      kPlayerSpriteFilePath,
      kPlayerWidth * frame_x, kPlayerHeight * frame_y,
      kPlayerWidth, kPlayerHeight
  );
}

unsigned int Player::GetFrameX(const Player::SpriteState &sprite_state) const {
  return sprite_state.current_frame_index;
}

unsigned int Player::GetFrameY(const Player::SpriteState &sprite_state) const {
  switch (sprite_state.horizontal_facing) {
    case HorizontalFacing::VERTICAL: return 0;
    case HorizontalFacing::LEFT: return 1;
    case HorizontalFacing::RIGHT: return 2;
    case HorizontalFacing::LAST: return 0;
  }
}

const Player::SpriteState Player::sprite_state() const {
  return SpriteState(
      horizontal_facing_,
      animation_.current()
  );
}

const double Player::speed() const {
  return speed_;
}
