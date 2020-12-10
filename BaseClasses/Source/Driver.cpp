//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/Driver.h"

#include <utility>

Driver::Driver() {
    _driversLicense = 0;
}

Driver::Driver(string name, int passportNumber, int driversLicense) : People(std::move(name), passportNumber) {
    _driversLicense = driversLicense;
}

Driver::Driver(const Driver &oldDriver) : People(oldDriver) {
    _driversLicense = oldDriver._driversLicense;
}

void Driver::setDriversLicense(int newDriversLicense) {
    _driversLicense = newDriversLicense;
}

int Driver::getDriversLicense() const {
    return _driversLicense;
}


Driver::~Driver() = default;
