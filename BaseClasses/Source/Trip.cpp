//
// Created by abmkrtchyan on 03.12.20.
//

#include "../Header/Trip.h"
#include <utility>

Trip::Trip(int id, string placeOfDeparture, string placeOfArrival, time_t departureTime, time_t arrivalTime, Bus *bus)
        : _id(id),
          _placeOfDeparture(std::move(placeOfDeparture)),
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
    this->_bus = new Bus(*oldTrip._bus);
}

int Trip::getId() const {
    return _id;
}

string Trip::getDepartureTime() const {
    tm *ptm = localtime(&_departureTime);
    char buffer[22];
    // Format: HH:MM DD.MM.YYYY , Mo
    strftime(buffer, 22, "%H:%M %d.%m.%Y , %a", ptm);
    return buffer;
}

void Trip::setDepartureTime(const time_t &newTime) {
    _departureTime = time_t(newTime);
}

string Trip::getArrivalTime() const {
    tm *ptm = localtime(&_arrivalTime);
    char buffer[22];
    // Format: HH:MM DD.MM.YYYY , Mo
    strftime(buffer, 22, "%H:%M %d.%m.%Y , %a", ptm);
    return buffer;
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

string Trip::getStatus() const {
    return std::string((const char *) _status);
}

void Trip::changeStatus() {
    (planned == _status) ? _status = inProgress : _status = finished;
}

Trip::Trip() {
    _departureTime = time_t(nullptr);
    _arrivalTime = time_t(nullptr);
    _status = finished;
    _bus = nullptr;
}

Bus *Trip::getBus() const {
    return _bus;
}

void Trip::printTripInfo(const Trip *trip) {
    if (trip != nullptr) {
        int id = trip->getId();
        string status = trip->getStatus();
        string from = trip->getPlaceOfDeparture();
        string to = trip->getPlaceOfArrival();
        string departure = trip->getDepartureTime();
        string arrival = trip->getArrivalTime();
        int freeSeatCount = trip->getBus()->getFreeSeatCount();
        printf("%-12s %-12s %-20s %-20s %-22s %-22s %-3s\n", "ID", "STATUS", "FROM", "TO", "DEPARTURE TIME",
               "ARRIVAL TIME", "FREE SEAT COUNT");
        printf("%-12d %-12s %-20s %-20s %-22s %-22s %-3d\n",
               id, status.c_str(), from.c_str(), to.c_str(), departure.c_str(), arrival.c_str(), freeSeatCount);
    }
}

void Trip::printTripsInfo(const std::vector <Trip> &trips) {
    printf("\e[1;1H\e[2J");
    int id;
    string status, from, to; //city
    string departure, arrival;//time
    int freeSeatCount;
    printf("%-12s %-12s %-20s %-20s %-22s %-22s %-3s\n", "ID", "STATUS", "FROM", "TO", "DEPARTURE TIME",
           "ARRIVAL TIME", "FREE SEAT COUNT");
    for (auto &trip:trips) {
        id = trip.getId();
        status = trip.getStatus();
        from = trip.getPlaceOfDeparture();
        to = trip.getPlaceOfArrival();
        departure = trip.getDepartureTime();
        arrival = trip.getArrivalTime();
        freeSeatCount = trip.getBus()->getFreeSeatCount();
        printf("%-12d %-12s %-20s %-20s %-22s %-22s %-3d\n",
               id, status.c_str(), from.c_str(), to.c_str(), departure.c_str(), arrival.c_str(), freeSeatCount);
    }
}

Trip::~Trip() = default;


