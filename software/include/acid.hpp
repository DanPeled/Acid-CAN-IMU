#include "BNO080.hpp"
#include "orientation.hpp"
namespace acid {
static BNO080 imu{Orientation::Zero};
// TODO: CAN Integration

void Init();
void Loop();
} // namespace acid
