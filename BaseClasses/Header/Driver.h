//
// Created by abmkrtchyan on 02.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_DRIVER_H
#define BUS_RESEVATION_SYSTEM_DRIVER_H

#include "People.h"

class Driver : public People {
private:
    int _driversLicense;
public:
    Driver();

    Driver(string name, string passportNumber, int driversLicense = 0);

    Driver(const Driver &oldDriver);

    int getDriversLicense() const;

    void setDriversLicense(int newDriversLicense);

    ~Driver();
};


#endif //BUS_RESEVATION_SYSTEM_DRIVER_H
