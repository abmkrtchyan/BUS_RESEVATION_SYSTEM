//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/Bus.h"

#include <utility>

Bus::Bus() {
    _busNumber = 0;
    _numberOfPassengers = 0;
    _isFree = false;
    _seats = nullptr;
};

Bus::Bus(string licensePlate, int numberOfPassengers, int busNumber, const Driver &driver) :
        _licensePlate(std::move(licensePlate)),
        _numberOfPassengers(numberOfPassengers),
        _busNumber(busNumber),
        _isFree(true),
        _driver(driver) {
    _seats = new Seat[_numberOfPassengers];
    for (int i = 0; i < _numberOfPassengers; ++i) {
        _seats[i]._seatNumber = i + 1;
    }
}

Bus::Bus(const Bus &oldBus) : _driver(std::string(), 0) {
    this->_numberOfPassengers = oldBus._numberOfPassengers;
    this->_isFree = oldBus._isFree;
    this->_licensePlate = oldBus._licensePlate;
    this->_busNumber = oldBus._busNumber;
    this->_seats = new Seat[oldBus._numberOfPassengers];
    for (int i = 0; i < oldBus._numberOfPassengers; ++i)
        this->_seats[i] = Seat(oldBus._seats[i]);
    this->_driver = Driver(oldBus._driver);
}

string Bus::getLicensePlate() {
    return _licensePlate;
}

void Bus::setLicensePlate(string newPlate) {
    _licensePlate = std::move(newPlate);
}

int Bus::getBusNumber() const {
    return _busNumber;
}

void Bus::setBusNumber(int newBusNumber) {
    _busNumber = newBusNumber;
}

int Bus::getNumberOfPassengers() const {
    return _numberOfPassengers;
}

void Bus::setNumberOfPassengers(int newCount) {
    _numberOfPassengers = newCount;
}

Driver Bus::getDriver() const {
    return Driver(_driver);
}

void Bus::setDriver(const Driver &newDriver) {
    _driver.setDriversLicense(newDriver.getDriversLicense());
    _driver.setName(newDriver.getName());
}

void Bus::setFree(bool x) {
    _isFree = x;
}

bool Bus::isFree() const {
    return _isFree;
}

Bus::~Bus() { delete[] _seats; }




