// #pragma once
#include "CustomAPMFirmwarePlugin.h"
#include "FirmwarePlugin.h"

CustomAPMFirmwarePlugin::CustomAPMFirmwarePlugin() {}

const QVariantList &
CustomAPMFirmwarePlugin::toolIndicators(const Vehicle *vehicle) {
    if (_toolIndicatorList.size() == 0) {
        _toolIndicatorList = FirmwarePlugin::toolIndicators(vehicle);
    }
    return _toolIndicatorList;
}
