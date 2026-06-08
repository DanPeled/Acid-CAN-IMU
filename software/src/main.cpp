#include "BNO080.hpp"
#include "orientation.hpp"
#include <cstdio>

int main() {
  stdio_init_all();
  acid::BNO080 imu;

  imu.Scan();

  while (true) {
    auto o = imu.GetOrientation();
    printf("Yaw: %f, Pitch: %f, Roll: %f\n", o.yaw, o.pitch, o.roll);
  }
}
