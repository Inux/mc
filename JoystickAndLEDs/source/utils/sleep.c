#include <utils/sleep.h>
#include "fsl_common.h"

void sleep(uint32_t timeout_in_ms) {
	SDK_DelayAtLeastUs((timeout_in_ms*1000), CLOCK_GetCoreSysClkFreq());
}
