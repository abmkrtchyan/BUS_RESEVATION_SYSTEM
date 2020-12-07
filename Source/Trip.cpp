//
// Created by abmkrtchyan on 03.12.20.
//

#include "../Header/Trip.h"

#include <utility>

Trip::Trip(string placeOfDeparture, string placeOfArrival, time_t departureTime, time_t arrivalTime, const Bus &bus)
        : _placeOfDeparture(std::move(placeOfDeparture)),
          _placeOfArrival(std::move(placeOfArrival)),
          _departureTime(departureTime),
          _arrivalTime(arrivalTime),
          _bus(bus),
          _status(planned) {}

Trip::Trip(const Trip &oldTrip) {
    this->_placeOfDeparture = oldTrip._placeOfDeparture;
    this->_placeOfArrival = oldTrip._placeOfArrival;
    this->_departureTime = time_t(oldTrip._departureTime);
    this->_arrivalTime = time_t(oldTrip._arrivalTime);
    this->_status = oldTrip._status;
    this->_bus = Bus(oldTrip._bus);
}

time_t Trip::getDepartureTime() const {
    return _departureTime;
}

void Trip::setDepartureTime(const time_t &newTime) {
    _departureTime = time_t(newTime);
}

time_t Trip::getArrivalTime() const {
    return _arrivalTime;
}

void Trip::setArrivalTime(const time_t &newTame) {
    _arrivalTime = time_t(newTame);
}

string Trip::getPlaceOfDeparture() const {
    return _placeOfDeparture;
}

string Trip::getPlaceOfArrival() const {
    return _placeOfArrival;
}

void Trip::changeStatus() {
    (planned == _status) ? _status = inProgress : _status = finished;
}

Trip::Trip() {
    _departureTime = time_t();
    _arrivalTime = time_t();
    _status = finished;
}

Trip::~Trip() = default;


