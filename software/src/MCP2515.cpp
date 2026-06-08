#include "MCP2515.hpp"
#include "spi.hpp"
#include <cstdint>
#include <hardware/gpio.h>
#include <hardware/spi.h>

void acid::MCP2515::CS_Low() { gpio_put(spi::SPI_CS, 0); }
void acid::MCP2515::CS_High() { gpio_put(spi::SPI_CS, 1); }
void acid::MCP2515::Transfer(uint8_t data) {
  spi_write_blocking(spi0, &data, 1);
}

void acid::MCP2515::Reset() {
  CS_Low();
  Transfer(RESET);
  CS_High();
}

uint8_t acid::MCP2515::Read(uint8_t addr) {
  uint8_t tx[3] = {READ, addr, 0};
  uint8_t rx[3];

  CS_Low();
  spi_write_read_blocking(spi0, tx, rx, 3);
  CS_High();

  return rx[2];
}

void acid::MCP2515::Write(uint8_t addr, uint8_t value) {
  uint8_t tx[3] = {WRITE, addr, value};

  CS_Low();
  spi_write_blocking(spi0, tx, 3);
  CS_High();
}
