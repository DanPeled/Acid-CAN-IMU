#include "BNO080.hpp"
#include "orientation.hpp"
#include "pico.hpp"
#include <cstdio>

int main() {
  acid::pico::Init();
  acid::BNO080 imu{Orientation::Zero};

  imu.Scan();

  while (true) {
    imu.Update();
    auto q = imu.GetQuaternion();
    printf("X: %f, Y: %f, Z: %f, W: %f", q.x, q.y, q.z, q.w);
  }
}
