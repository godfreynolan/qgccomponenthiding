// #pragma once
#include <string>
#include "AccessType.h"

static const char *enumStrings[] = { "Basic", "Expert", "Factory" };

std::string accessTypeString(AccessType accessType) {
    return enumStrings[accessType];
};
