#ifndef CUSTOMFIRMWAREPLUGINFACTORY_H
#define CUSTOMFIRMWAREPLUGINFACTORY_H
#pragma once

#include "FirmwarePlugin.h"

class CustomPX4FirmwarePlugin;

class CustomFirmwarePluginFactory : public FirmwarePluginFactory
{
    Q_OBJECT
public:
    CustomFirmwarePluginFactory();
    QList<QGCMAVLink::FirmwareClass_t>  supportedFirmwareClasses(void) const final;
    FirmwarePlugin*                     firmwarePluginForAutopilot  (MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType) final;

private:
    CustomPX4FirmwarePlugin*   _pluginInstance;
};

extern CustomFirmwarePluginFactory CustomFirmwarePluginFactoryImp;

#endif // CUSTOMFIRMWAREPLUGINFACTORY_H
