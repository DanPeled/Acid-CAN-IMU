#pragma once
#include "sh2.h"
#include <bno08x.h>
#include <cstdint>

namespace acid {
class BNO080 {
public:
  BNO080(const sh2_Quaternion_t &initialOrientation);

public:
  void Scan();
  void Update();
  bool Reset();

public:
  sh2_Quaternion_t GetQuaternion() const;
  float GetQuatRadianAccuracy() const;
  uint8_t GetAccelAccuracy() const;
  uint8_t GetLinAccelAccuracy() const;

private:
  bool Poll();

private:
  BNO08x m_imu;
  sh2_Quaternion_t m_quaternion;
  float m_quatRadianAccuracy;
  uint8_t m_accelAccuracy;
  uint8_t m_linAccelAccuracy;
};
} // namespace acid
