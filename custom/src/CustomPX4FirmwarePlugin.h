#ifndef CUSTOMPX4FIRMWAREPLUGIN_H
#define CUSTOMPX4FIRMWAREPLUGIN_H
#pragma once

#include "FirmwarePlugin.h"
#include "PX4FirmwarePlugin.h"

class CustomPX4FirmwarePlugin : public PX4FirmwarePlugin {
    Q_OBJECT
  public:
    CustomPX4FirmwarePlugin();
    const QVariantList &toolIndicators(const Vehicle *vehicle) final;

  private:
    QVariantList _toolIndicatorList;
};

#endif // CUSTOMPX4FIRMWAREPLUGIN_H
