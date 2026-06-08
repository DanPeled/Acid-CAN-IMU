#include "spi.hpp"
#include <hardware/gpio.h>
#include <hardware/spi.h>

void acid::spi::InitSPI() {
  spi_init(spi0, 1'000'000);
  gpio_set_function(SPI_SCK, GPIO_FUNC_SPI);
  gpio_set_function(SPI_MOSI, GPIO_FUNC_SPI);
  gpio_set_function(SPI_MISO, GPIO_FUNC_SPI);

  gpio_init(SPI_CS);
  gpio_set_dir(SPI_CS, GPIO_OUT);
  gpio_put(SPI_CS, 1);
}
