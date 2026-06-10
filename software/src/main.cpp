#include "acid.hpp"

int main() {
  acid::Init();

  while (true) {
    acid::Loop();
  }
}
