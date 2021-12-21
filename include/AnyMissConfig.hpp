#pragma once

#include "config-utils/shared/config-utils.hpp"

DECLARE_CONFIG(AnyMissConfig,
    CONFIG_VALUE(HideMissText, bool, "HideMissText", true);
    CONFIG_VALUE(HideFCBreakLinesAnimation, bool, "HideFCBreakLinesAnimation", true);

    CONFIG_INIT_FUNCTION(
        CONFIG_INIT_VALUE(HideMissText);
        CONFIG_INIT_VALUE(HideFCBreakLinesAnimation);
    )
)