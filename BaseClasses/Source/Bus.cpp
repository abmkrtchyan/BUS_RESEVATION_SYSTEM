//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/Bus.h"

#include <utility>

Bus::Bus() {
    _freeSeatCount = 0;
    _numberOfPassengers = 0;
    _isFree = false;
    _seats = nullptr;
    _driver = nullptr;
}

Bus::Bus(string licensePlate, int numberOfPassengers, Driver *driver) :
        _licensePlate(std::move(licensePlate)),
        _numberOfPassengers(numberOfPassengers),
        _freeSeatCount(numberOfPassengers),
        _isFree(true),
        _driver(driver) {
    _seats = new Seat[_numberOfPassengers];
    for (int i = 0; i < _numberOfPassengers; ++i) {
        _seats[i]._seatNumber = i + 1;
    }
}

Bus::Bus(const Bus &oldBus) {
    this->_numberOfPassengers = oldBus._numberOfPassengers;
    this->_isFree = oldBus._isFree;
    this->_licensePlate = oldBus._licensePlate;
    this->_freeSeatCount = oldBus._freeSeatCount;
    this->_seats = new Seat[oldBus._numberOfPassengers];
    for (int i = 0; i < oldBus._numberOfPassengers; ++i)
        this->_seats[i] = Seat(oldBus._seats[i]);
    this->_driver = new Driver(*oldBus._driver);
}

string Bus::getLicensePlate() {
    return _licensePlate;
}

void Bus::setLicensePlate(string newPlate) {
    _licensePlate = std::move(newPlate);
}

int Bus::getFreeSeatCount() const {
    return _freeSeatCount;
}

void Bus::setFreeSeatCount(int newCount) {
    _freeSeatCount = newCount;
}

int Bus::getNumberOfPassengers() const {
    return _numberOfPassengers;
}

void Bus::setNumberOfPassengers(int newCount) {
    _numberOfPassengers = newCount;
}

Driver *Bus::getDriver() const {
    return _driver;
}

void Bus::setDriver(const Driver &newDriver) {
    _driver->setDriversLicense(newDriver.getDriversLicense());
    _driver->setName(newDriver.getName());
}

void Bus::setFree(bool x) {
    _isFree = x;
}

bool Bus::isFree() const {
    return _isFree;
}

//Printing bus information
void Bus::print() {
    printf("\n%s:\n", "Printing bus information");
    printf("%-30s %-15s \n", "Licence plate number: --> ", _licensePlate.c_str());
    printf("%-30s %-15s \n", "Driver name: --> ", _driver->getName().c_str());
    printf("%-30s %-8d \n", "Number of passengers: --> ", _numberOfPassengers);
    printf("%-30s %-8d \n\n", "Free Seat count: --> ", _freeSeatCount);
    printf("%-30s\n", "Free seat numbers: ");
    for (int i = 0; i < _numberOfPassengers; ++i) {
        if (_seats[i]._isFree)
            printf("%-4d", _seats[i]._seatNumber);
    }
}

bool Bus::reserveSeat(int seatNumber, People *people) {
    if (seatNumber > 0 && seatNumber <= _numberOfPassengers && _seats[seatNumber + 1]._isFree) {
        _seats[seatNumber + 1]._isFree = false;
        _seats[seatNumber + 1]._people = people;
        _freeSeatCount--;
        return true;
    } else return false;
}

Bus::~Bus() = default;
/*string _licensePlate;
int _freeSeatCount;
int _numberOfPassengers;
Seat *_seats;
Driver *_driver;
bool _isFree; //bus
Bus::~Bus() { delete[] _seats; }*/






