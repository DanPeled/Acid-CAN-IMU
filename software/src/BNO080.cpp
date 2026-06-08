#include "BNO080.hpp"
#include "bno08x.h"
#include "orientation.hpp"
#include "utils.h"
#include <hardware/i2c.h>

using namespace acid;

i2c_inst_t *i2c_port0;

void BNO080::Scan() {
  initI2C(i2c_port0, false);
  while (!m_imu.begin(CONFIG::BNO08X_ADDR, i2c_port0)) {
    printf("IMU Not detected at default i2c address. Check Wiring. Freezing\n");
    scan_i2c_bus();
  }
  m_imu.enableRotationVector();
}

void BNO080::Update() {
  if (m_imu.getSensorEvent()) {
    if (m_imu.getSensorEventID() == SENSOR_REPORTID_ROTATION_VECTOR) {
      m_orientation = {m_imu.getYaw(), m_imu.getPitch(), m_imu.getRoll()};
    }
  }
}

bool BNO080::Reset() { return m_imu.softReset(); }

Orientation BNO080::GetOrientation() const { return m_orientation; }
