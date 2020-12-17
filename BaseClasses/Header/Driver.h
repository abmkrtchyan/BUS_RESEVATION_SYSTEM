//
// Created by abmkrtchyan on 02.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_DRIVER_H
#define BUS_RESEVATION_SYSTEM_DRIVER_H

#include "People.h"

class Driver : public People {
private:
    string _driversLicense;
public:
    Driver();

    Driver(string name, string passportNumber, string driversLicense);

    Driver(const Driver &oldDriver);

    string getDriversLicense() const;

    void setDriversLicense(string newDriversLicense);

    ~Driver();
};


#endif //BUS_RESEVATION_SYSTEM_DRIVER_H
