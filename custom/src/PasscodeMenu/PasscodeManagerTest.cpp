#include "PasscodeManagerTest.h"
#include "PasscodeManager.h"

PasscodeManagerTest::PasscodeManagerTest() {};

void PasscodeManagerTest::_testPasscodeManager() {
    PasscodeManager *myPasscodeManager = new PasscodeManager();
    myPasscodeManager->setConfigFile(".\\testUserAccessConfig.txt");
    std::list<QString> expectedPasscodes = { "PasswordForExpert", "PasswordForFactory" };
    std::list<QString> actualPasscodes = myPasscodeManager->getPasscodes();
    QCOMPARE(expectedPasscodes, actualPasscodes);
};
