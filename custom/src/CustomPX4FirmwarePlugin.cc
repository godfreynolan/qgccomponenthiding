// #pragma once
#include "CustomPX4FirmwarePlugin.h"
#include "AccessTypeConfig.cpp"
#include "FirmwarePlugin.h"

CustomPX4FirmwarePlugin::CustomPX4FirmwarePlugin() {
    for (int i = 0; i < _flightModeInfoList.count(); i++) {
        FlightModeInfo_t &info = _flightModeInfoList[i];
        if (CURRENT_USER_ACCESS_TYPE == Basic ||
            CURRENT_USER_ACCESS_TYPE == Expert) {
            if (info.name != _acroFlightMode) {
                info.canBeSet = false;
            }
        }
    }
}

const QVariantList &
CustomPX4FirmwarePlugin::toolIndicators(const Vehicle *vehicle) {
    if (_toolIndicatorList.size() == 0) {
        _toolIndicatorList = FirmwarePlugin::toolIndicators(vehicle);
        // Then specifically remove the RC RSSI indicator.
        //        _toolIndicatorList.removeOne(QVariant::fromValue(QUrl::fromUserInput("qrc:/toolbar/RCRSSIIndicator.qml")));
    }
    return _toolIndicatorList;
}
