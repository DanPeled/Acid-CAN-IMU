#pragma once
#include "bno08x.h"
#include "orientation.hpp"

namespace acid {
class BNO080 {
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
