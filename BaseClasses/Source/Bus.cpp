//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/Bus.h"

#include <utility>

Bus::Bus() {
    _freeSeatCount = 0;
    _numberOfPassengers = 0;
    _status = false;
    _seats = nullptr;
    _driver = nullptr;
}

Bus::Bus(string licensePlate, int numberOfPassengers, Driver *driver) :
        _licensePlate(std::move(licensePlate)),
        _numberOfPassengers(numberOfPassengers),
        _freeSeatCount(numberOfPassengers),
        _status(true) {
    _driver = new Driver(*driver);
    _seats = new Seat[_numberOfPassengers];
    for (int i = 0; i < _numberOfPassengers; ++i) {
        _seats[i]._seatNumber = i + 1;
    }
}

Bus::Bus(string licensePlate, int freeSeatCount, int numberOfPassengers, Driver *driver, bool status,
         const std::map<int, std::pair<People *, bool>> &seats) :
        _licensePlate(std::move(licensePlate)),
        _numberOfPassengers(numberOfPassengers),
        _freeSeatCount(freeSeatCount),
        _status(status) {
    _driver = new Driver(*driver);
    _seats = new Seat[_numberOfPassengers];
    int index = 0;

    for (auto &seat:seats) {
        _seats[index]._seatNumber = seat.first;
        _seats[index]._isFree = seat.second.second;
        if (seat.second.first != nullptr)
            _seats[index]._people = new People(*seat.second.first);
        else _seats[index]._people = nullptr;
        index++;
    }
}

Bus::Bus(const Bus &oldBus) {
    this->_numberOfPassengers = oldBus._numberOfPassengers;
    this->_status = oldBus._status;
    this->_licensePlate = oldBus._licensePlate;
    this->_freeSeatCount = oldBus._freeSeatCount;
    this->_seats = new Seat[oldBus._numberOfPassengers];
    for (int i = 0; i < oldBus._numberOfPassengers; ++i)
        this->_seats[i] = Seat(oldBus._seats[i]);
    this->_driver = new Driver(*oldBus._driver);
}

string Bus::getLicensePlate() const {
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
    _status = x;
}

bool Bus::isFree() const {
    return _status;
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

void Bus::printAll() {
    printf("\n%s:\n", "Printing bus information");
    printf("%-30s %-15s \n", "Licence plate number: --> ", _licensePlate.c_str());
    printf("%-30s %-15s \n", "Driver name: --> ", _driver->getName().c_str());
    printf("%-30s %-8d \n", "Number of passengers: --> ", _numberOfPassengers);
    printf("%-30s %-8d \n\n", "Free Seat count: --> ", _freeSeatCount);
    printf("%-30s\n", "Seat: ");
    printf("%-12s %-12s %-20s %-20s\n", "SEAT NUMBER", "STATUS", "PEOPLE PASSPORT", "NAME");

    for (int i = 0; i < _numberOfPassengers; ++i) {
        printf("%-12d %-12s %-20s %-20s\n",
               _seats[i]._seatNumber,
               _seats[i]._isFree ? "Free" : "Busy",
               _seats[i]._isFree ? _seats[i]._people->getPassportId().c_str() : "",
               _seats[i]._isFree ? _seats->_people->getName().c_str() : "");
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

std::map<int, std::pair<string, bool>> Bus::getSeat() const {
    std::map<int, std::pair<string, bool>> map;
    for (int i = 0; i < _numberOfPassengers; i++) {
        string peopleID = _seats->_people == nullptr ? "NULL" : _seats->_people->getPassportId();
        map[_seats[i]._seatNumber] = std::make_pair(peopleID, _seats[i]._isFree);
    }
    return map;
}

Bus::~Bus() = default;
/*string _licensePlate;
int _freeSeatCount;
int _numberOfPassengers;
Seat *_seats;
Driver *_driver;
bool _isFree; //bus
Bus::~Bus() { delete[] _seats; }*/






