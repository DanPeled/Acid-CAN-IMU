#pragma once

#include "sh2.h"
struct Orientation {
  float yaw, pitch, roll;

  Orientation operator+(const Orientation &o);
  Orientation operator-(const Orientation &o);

  operator sh2_Quaternion_t() const;

  static const Orientation Zero;
};
