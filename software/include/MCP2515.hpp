#pragma once

#include <cstdint>
#include <hardware/spi.h>

namespace acid {

class MCP2515 {
public:
  enum class Register : uint8_t {
    CANSTAT = 0x0E,
    CANCTRL = 0x0F,
    CNF1 = 0x2A,
    CNF2 = 0x29,
    CNF3 = 0x28,
  };

  static constexpr uint8_t RESET = 0xC0;
  static constexpr uint8_t READ = 0x03;
  static constexpr uint8_t WRITE = 0x02;
  static constexpr uint8_t BIT_MODIFY = 0x05;
  static constexpr uint8_t READ_STATUS = 0xA0;

public:
  void Init();
  void Reset();
  uint8_t Read(uint8_t addr);
  void Write(uint8_t addr, uint8_t value);

private:
  void CS_Low();
  void CS_High();
  void Transfer(uint8_t data);
};
} // namespace acid
