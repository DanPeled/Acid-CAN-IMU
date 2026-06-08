#pragma once

struct Orientation {
  float yaw, pitch, roll;

  Orientation operator+(const Orientation &o);
  Orientation operator-(const Orientation &o);

  static const Orientation Zero;
};
