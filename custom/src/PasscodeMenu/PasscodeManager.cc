#include "PasscodeManager.h"
#include <iostream>
#include <fstream>
#include <string>
#include <QDebug>

using namespace std;

PasscodeManager::PasscodeManager() {
    this->setConfigFile(".\\userAccessConfig.txt");
}

PasscodeManager::~PasscodeManager() {}

list<QString> PasscodeManager::getPasscodes() {
    return this->_passcodes;
}

void PasscodeManager::setConfigFile(string fileName) {
    this->_configFile = fileName;
    this->_initPasscodes();
}

void PasscodeManager::_initPasscodes() {
    fstream passcodeConfigFile;
    passcodeConfigFile.open(this->_configFile, ios::in);
    string line;
    int i = 0;
    while(getline(passcodeConfigFile, line)) {
        this->_passcodes.push_back(QString::fromStdString(line));
        i++;
    }
    passcodeConfigFile.close();
    qDebug() << "Passcodes Loaded:";
    qDebug() << this->_passcodes.size();
}

QString PasscodeManager::submitPasscode(QString passcode) {
    QString accessLevels[] = {
        "Expert",
        "Factory",
    };
    int i = 0;
    for (list<QString>::iterator iter = this->_passcodes.begin(); iter != this->_passcodes.end(); iter++) {
        if (passcode == *iter) {
            return accessLevels[i];
        }
        i++;
    }
    return "";
}
