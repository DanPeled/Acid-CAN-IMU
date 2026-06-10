#include "acid.hpp"
#include "pico.hpp"

void acid::Init() {
  pico::Init();
  imu.Scan();
}

void acid::Loop() {
  imu.Update();
  auto q = imu.GetQuaternion();
  printf("X: %f, Y: %f, Z: %f, W: %f", q.x, q.y, q.z,
         q.w); // TODO: Sending via CAN to the robot
}
