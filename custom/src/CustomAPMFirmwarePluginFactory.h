#ifndef CUSTOMAPMFIRMWAREPLUGINFACTORY_H
#define CUSTOMAPMFIRMWAREPLUGINFACTORY_H
#pragma once

#include "FirmwarePlugin.h"

class CustomAPMFirmwarePlugin;
class ArduCopterFirmwarePlugin;
class ArduPlaneFirmwarePlugin;
class ArduRoverFirmwarePlugin;
class ArduSubFirmwarePlugin;

class CustomAPMFirmwarePluginFactory : public FirmwarePluginFactory
{
    Q_OBJECT
public:
    CustomAPMFirmwarePluginFactory();
    QList<QGCMAVLink::FirmwareClass_t>  supportedFirmwareClasses(void) const final;
    FirmwarePlugin*                     firmwarePluginForAutopilot  (MAV_AUTOPILOT autopilotType, MAV_TYPE vehicleType) final;

private:
    ArduCopterFirmwarePlugin*   _arduCopterPluginInstance;
    ArduPlaneFirmwarePlugin*    _arduPlanePluginInstance;
    ArduRoverFirmwarePlugin*    _arduRoverPluginInstance;
    ArduSubFirmwarePlugin*      _arduSubPluginInstance;
};

extern CustomAPMFirmwarePluginFactory CustomFirmwarePluginFactoryImp1;

#endif // CUSTOMAPMFIRMWAREPLUGINFACTORY_H
