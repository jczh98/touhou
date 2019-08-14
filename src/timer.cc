/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#include "timer.h"

std::set<Timer *> Timer::timers_;

Timer::Timer(std::chrono::milliseconds expiration_time, bool start_active) :
    current_time_{start_active ? 0 : expiration_time.count() + 1},
    expiration_time_{expiration_time} {
  timers_.insert(this);
}

Timer::~Timer() {
  timers_.erase(this);
}

void Timer::Reset() {
  current_time_ = std::chrono::milliseconds::zero();
}

bool Timer::is_active() const {
  return current_time_ < expiration_time_;
}

bool Timer::is_expired() const {
  return !is_active();
}

std::chrono::milliseconds Timer::current_time() const {
  return current_time_;
}

void Timer::UpdateAll(std::chrono::milliseconds elapsed_time) {
  for (auto timer: timers_) {
    timer->Update(elapsed_time);
  }
}

void Timer::Update(std::chrono::milliseconds elapsed_time) {
  if (is_active()) {
    current_time_ += elapsed_time;
  }
}
