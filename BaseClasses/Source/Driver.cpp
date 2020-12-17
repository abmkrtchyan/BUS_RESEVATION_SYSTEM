//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/Driver.h"

#include <utility>

Driver::Driver() {
    _driversLicense ;
}

Driver::Driver(string name, string passportNumber, string driversLicense) : People(std::move(name),
                                                                                   std::move(passportNumber)) {
    _driversLicense = std::move(driversLicense);
}

Driver::Driver(const Driver &oldDriver) : People(oldDriver) {
    _driversLicense = oldDriver._driversLicense;
}

void Driver::setDriversLicense(string newDriversLicense) {
    _driversLicense = std::move(newDriversLicense);
}

string Driver::getDriversLicense() const {
    return _driversLicense;
}


Driver::~Driver() = default;
