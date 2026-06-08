#pragma once

#include <pico/types.h>

namespace acid::spi {
constexpr uint SPI_SCK = 18;
constexpr uint SPI_MOSI = 19;
constexpr uint SPI_MISO = 16;
constexpr uint SPI_CS = 17;

void InitSPI();
} // namespace acid::spi
