#pragma once
#include "orientation.hpp"
#include <bno08x.h>

namespace acid {
class BNO080 {
public:
  BNO080(const Orientation &initialOrientation);

public:
  void Scan();
  void Update();
  bool Reset();

public:
  Orientation GetOrientation() const;

private:
  BNO08x m_imu;
  Orientation m_orientation;
};
} // namespace acid
