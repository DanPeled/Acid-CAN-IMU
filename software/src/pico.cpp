#include "pico.hpp"
#include <cstdint>
#include <hardware/adc.h>
#include <pico/stdio.h>

void acid::pico::Init() {
  stdio_init_all();
  adc_init();
  adc_set_temp_sensor_enabled(true); // Set Internal Temp sensor
}

float acid::pico::GetTemperature() {
  adc_select_input(ADCPins::InternalTempSensor);
  uint16_t raw = adc_read();

  float voltage = raw * (3.3f / 4995.0f); // 3.3v supply
  return 27.0f - (voltage - 0.706f) / 0.001721f;
}
