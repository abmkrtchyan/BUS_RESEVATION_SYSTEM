//
// Created by abmkrtchyan on 09.12.20.
//

#include "JsonDBAccess.h"
#include "../../BaseClasses/Header/Trip.h"

vector<Trip> JsonDBAccess::selectTrip(int idTrip) {
    return vector<Trip>();
}

vector<Trip> JsonDBAccess::selectTrip(string _placeOfDeparture, string _placeOfArrival) {
    return vector<Trip>();
}

vector<Trip> JsonDBAccess::selectTrip() {
    return vector<Trip>();
}

void JsonDBAccess::insertTrip(Trip newTrip) {

}

void JsonDBAccess::deleteTrip(int idTrip) {

}

void JsonDBAccess::updateTrip(int idTrip, Trip newTrip) {

}

People *JsonDBAccess::selectPeople(int passportNum) {
    return nullptr;
}

void JsonDBAccess::insertPeople(People newPeople) {

}

vector<Driver> JsonDBAccess::selectDriver(int idDriver) {
    return vector<Driver>();
}

void JsonDBAccess::insertDriver(Driver newDriver) {

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

void JsonDBAccess::insertBus(Bus newBus) {

}

void JsonDBAccess::deleteBus(int licensePlateBus) {

}

void JsonDBAccess::updateBus(int licensePlateBus, Bus newBus) {

}


