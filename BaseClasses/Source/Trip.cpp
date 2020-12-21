//
// Created by abmkrtchyan on 03.12.20.
//

#include "../Header/Trip.h"
#include <utility>

Trip::Trip(string id, string placeOfDeparture, string placeOfArrival, time_t departureTime, time_t arrivalTime,
           Bus *bus, const char *status)
        : _id(std::move(id)),
          _placeOfDeparture(std::move(placeOfDeparture)),
          _placeOfArrival(std::move(placeOfArrival)),
          _departureTime(departureTime),
          _arrivalTime(arrivalTime),
          _bus(bus) { _status = returnStatus(status); }

Trip::Trip(const Trip &oldTrip) {
    this->_id = oldTrip.getId();
    this->_placeOfDeparture = oldTrip._placeOfDeparture;
    this->_placeOfArrival = oldTrip._placeOfArrival;
    this->_departureTime = time_t(oldTrip._departureTime);
    this->_arrivalTime = time_t(oldTrip._arrivalTime);
    this->_status = oldTrip._status;
    this->_bus = new Bus(*oldTrip._bus);
}

string Trip::getId() const {
    return _id;
}

void Trip::setID(string newID) {
    this->_id = std::move(newID);
}

string Trip::getDepartureTime() const {
    tm *ptm = localtime(&_departureTime);
    char buffer[22];
    // Format: HH:MM DD.MM.YYYY , Mo
    strftime(buffer, 22, "%H:%M %d.%m.%Y", ptm);
    return buffer;
}

void Trip::setDepartureTime(const time_t &newTime) {
    _departureTime = time_t(newTime);
}

string Trip::getArrivalTime() const {
    tm *ptm = localtime(&_arrivalTime);
    char buffer[22];
    // Format: HH:MM DD.MM.YYYY
    strftime(buffer, 22, "%H:%M %d.%m.%Y", ptm);
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
    if (_status == planned)
        return "planned";
    else if (_status == inProgress)
        return "inProgress";
    else if (_status == finished)
        return "finished";
    else return "indefinite";
}

void Trip::setStatus(const string &newStatus) {
    _status = returnStatus(newStatus);
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
        string id = trip->getId();
        string status = trip->getStatus();
        string from = trip->getPlaceOfDeparture();
        string to = trip->getPlaceOfArrival();
        string departure = trip->getDepartureTime();
        string arrival = trip->getArrivalTime();
        int freeSeatCount = trip->getBus()->getFreeSeatCount();
        printf("%-30s %-12s %-20s %-20s %-22s %-22s %-3s\n", "ID", "STATUS", "FROM", "TO", "DEPARTURE TIME",
               "ARRIVAL TIME", "FREE SEAT COUNT");
        printf("%-30s %-12s %-20s %-20s %-22s %-22s %-3d\n",
               id.c_str(), status.c_str(), from.c_str(), to.c_str(), departure.c_str(), arrival.c_str(), freeSeatCount);
    }
}

void Trip::printTripsInfo(const std::vector<Trip> &trips) {
    printf("\e[1;1H\e[2J");
    string id;
    string status, from, to; //city
    string departure, arrival;//time
    int freeSeatCount;
    printf("%-30s %-12s %-20s %-20s %-22s %-22s %-3s\n", "ID", "STATUS", "FROM", "TO", "DEPARTURE TIME",
           "ARRIVAL TIME", "FREE SEAT COUNT");
    for (auto &trip:trips) {
        id = trip.getId();
        status = trip.getStatus();
        from = trip.getPlaceOfDeparture();
        to = trip.getPlaceOfArrival();
        departure = trip.getDepartureTime();
        arrival = trip.getArrivalTime();
        freeSeatCount = trip.getBus()->getFreeSeatCount();
        printf("%-30s %-12s %-20s %-20s %-22s %-22s %-3d\n",
               id.c_str(), status.c_str(), from.c_str(), to.c_str(), departure.c_str(), arrival.c_str(), freeSeatCount);
    }
}

Trip::Status Trip::returnStatus(const string &status) {
    if (status == "planned")
        return planned;
    else if (status == "inProgress")
        return inProgress;
    else if (status == "finished")
        return finished;
    else return indefinite;

}

Trip::~Trip() = default;


