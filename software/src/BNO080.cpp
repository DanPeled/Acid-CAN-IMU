#include "BNO080.hpp"
#include "bno08x.h"
#include "sh2.h"
#include <cstdint>
#include <utils.h>

using namespace acid;

i2c_inst_t *i2c_port0;

BNO080::BNO080(const sh2_Quaternion_t &initialOrientation)
    : m_quaternion(initialOrientation) {};

void BNO080::Scan() {
  initI2C(i2c_port0, false);

  while (!m_imu.begin(CONFIG::BNO08X_ADDR, i2c_port0)) {
    printf("IMU Not detected at default i2c address. Check Wiring. Freezing\n");
    scan_i2c_bus();
  }

  m_imu.enableRotationVector();
}

bool BNO080::Update() {
  if (!m_imu.getSensorEvent())
    return false;

  if (m_imu.getSensorEventID() != SENSOR_REPORTID_ROTATION_VECTOR)
    return false;

  m_quaternion = {.x = m_imu.getGameQuatI(),
                  .y = m_imu.getGameQuatJ(),
                  .z = m_imu.getGameQuatK(),
                  .w = m_imu.getGameQuatReal()};

  m_quatRadianAccuracy = m_imu.getQuatRadianAccuracy();
  m_accelAccuracy = m_imu.getAccelAccuracy();
  m_linAccelAccuracy = m_imu.getLinAccelAccuracy();

  return true;
}

bool BNO080::Reset() { return m_imu.softReset(); }

sh2_Quaternion_t BNO080::GetQuaternion() const { return m_quaternion; }

uint8_t BNO080::GetAccelAccuracy() const { return m_accelAccuracy; }
uint8_t BNO080::GetLinAccelAccuracy() const { return m_linAccelAccuracy; }
float BNO080::GetQuatRadianAccuracy() const { return m_quatRadianAccuracy; }
