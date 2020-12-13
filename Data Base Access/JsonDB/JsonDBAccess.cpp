//
// Created by abmkrtchyan on 09.12.20.
//

#include "JsonDBAccess.h"
#include "../../BaseClasses/Header/Trip.h"

Trip *JsonDBAccess::selectTrip(int idTrip) {
    return nullptr;
}

vector<Trip> JsonDBAccess::selectTrip(string _placeOfDeparture, string _placeOfArrival) {
    return vector<Trip>();
}

vector<Trip> JsonDBAccess::selectTrip(string driverLicenseNumber) {
    return vector<Trip>();
}


vector<Trip> JsonDBAccess::selectTrip() {
    return vector<Trip>();
}

bool JsonDBAccess::insertTrip(Trip newTrip) {
    return true;
}

void JsonDBAccess::deleteTrip(int idTrip) {

}

void JsonDBAccess::updateTrip(int idTrip, Trip newTrip) {

}

People *JsonDBAccess::selectPeople(string passportNum) {
    People *driver = new Driver("Abo", "1234", "5678");
    return driver;
}

void JsonDBAccess::insertPeople(People newPeople) {

}

vector<Driver> JsonDBAccess::selectDriver(int idDriver) {
    return vector<Driver>();
}

bool JsonDBAccess::insertDriver(Driver newDriver) {
    return true;
}

void JsonDBAccess::deleteDriver(int idDriver) {

}

void JsonDBAccess::updateDriver(int idDriver, Driver newDriver) {

}

vector<Bus> JsonDBAccess::selectBus(int licensePlate) {
    return vector<Bus>();
}

vector<Bus> JsonDBAccess::selectBus(int maxNumberOfPassengers, int minNumberOfPassengers) {
    return vector<Bus>();
}

vector<Bus> JsonDBAccess::selectBus(bool freeBuses) {
    return vector<Bus>();
}

bool JsonDBAccess::insertBus(Bus newBus) {
    return true;
}

void JsonDBAccess::deleteBus(int licensePlateBus) {

}

void JsonDBAccess::updateBus(int licensePlateBus, Bus newBus) {

}


