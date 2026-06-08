#include "orientation.hpp"

const Orientation Orientation::Zero{0, 0, 0};

Orientation Orientation::operator+(const Orientation &o) {
  return {.yaw = yaw + o.yaw, .pitch = pitch + o.pitch, .roll = roll + o.roll};
}

Orientation Orientation::operator-(const Orientation &o) {
  return {.yaw = yaw - o.yaw, .pitch = pitch - o.pitch, .roll = roll - o.roll};
}
