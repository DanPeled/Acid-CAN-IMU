#pragma once

#include <cstdint>
namespace acid::pico {
enum ADCPins : uint8_t {
  InternalTempSensor = 4,
};

void Init();
float GetTemperature();
} // namespace acid::pico
