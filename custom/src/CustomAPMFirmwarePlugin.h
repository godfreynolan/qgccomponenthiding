#ifndef CUSTOMAPMFIRMWAREPLUGIN_H
#define CUSTOMAPMFIRMWAREPLUGIN_H
#pragma once

#include "FirmwarePlugin.h"
#include "APMFirmwarePlugin.h"

class CustomAPMFirmwarePlugin : public APMFirmwarePlugin {
    Q_OBJECT
  public:
    CustomAPMFirmwarePlugin();
    const QVariantList &toolIndicators(const Vehicle *vehicle) final;

  private:
    QVariantList _toolIndicatorList;
};

#endif // CUSTOMAPMFIRMWAREPLUGIN_H
