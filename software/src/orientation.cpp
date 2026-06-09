#include "orientation.hpp"
#include "sh2.h"
#include <cmath>

const Orientation Orientation::Zero{0, 0, 0};

Orientation Orientation::operator+(const Orientation &o) {
  return {.yaw = yaw + o.yaw, .pitch = pitch + o.pitch, .roll = roll + o.roll};
}

Orientation Orientation::operator-(const Orientation &o) {
  return {.yaw = yaw - o.yaw, .pitch = pitch - o.pitch, .roll = roll - o.roll};
}

Orientation::operator sh2_Quaternion() const {
  sh2_Quaternion_t q;

  float cy = cosf(yaw * 0.5f);
  float sy = sinf(yaw * 0.5f);
  float cp = cosf(pitch * 0.5f);
  float sp = sinf(pitch * 0.5f);
  float cr = cosf(roll * 0.5f);
  float sr = sinf(roll * 0.5f);

  q.w = cr * cp * cy + sr * sp * sy;
  q.x = sr * cp * cy - cr * sp * sy;
  q.y = cr * sp * cy + sr * cp * sy;
  q.z = cr * cp * sy - sr * sp * cy;

  return q;
}
