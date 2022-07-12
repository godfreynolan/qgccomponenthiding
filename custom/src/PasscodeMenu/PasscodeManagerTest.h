#ifndef PASSCODEMANAGERTEST_H
#define PASSCODEMANAGERTEST_H
#pragma once

#include <qgcunittest/UnitTest.h>

class PasscodeManagerTest : public UnitTest {
    Q_OBJECT

    public:
        PasscodeManagerTest(void);

    private slots:
        void _testPasscodeManager(void);
};
#endif // PASSCODEMANAGERTEST_H
