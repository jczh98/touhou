/*
 * Copyright (C) 2018-2019, neverfelly <neverfelly@gmail.com>
 *
 * This software is licensed under the terms of the MIT License.
 * See COPYING for further information.
 */

#ifndef TOUHOU_SRC_TIMER_H_
#define TOUHOU_SRC_TIMER_H_

#include <chrono>
#include <set>

struct Timer {
  explicit Timer(std::chrono::milliseconds expiration_time, bool start_active = false);
  Timer(const Timer &) = delete;
  Timer &operator=(const Timer &) = delete;
  ~Timer();

  void Reset();
  bool is_active() const;
  bool is_expired() const;

  std::chrono::milliseconds current_time() const;

  static void UpdateAll(std::chrono::milliseconds elapsed_time);

 private:
  void Update(std::chrono::milliseconds elapsed_time);
  std::chrono::milliseconds current_time_;
  const std::chrono::milliseconds expiration_time_;

  static std::set<Timer *> timers_;
};

#endif //TOUHOU_SRC_TIMER_H_
