//
// Created by abmkrtchyan on 03.12.20.
//
#include <string>
#include <time.h>
#include "Bus.h"
#include <vector>

using std::string;
#ifndef BUS_RESEVATION_SYSTEM_TRIP_H
#define BUS_RESEVATION_SYSTEM_TRIP_H


class Trip {
    enum Status {
        planned, inProgress, finished, indefinite
    };
private:
    string _id ;
    time_t _departureTime;
    time_t _arrivalTime;
    string _placeOfDeparture;
    string _placeOfArrival;
    Bus *_bus;
    Status _status;
public:
    Trip();

    Trip(string id, string placeOfDeparture, string placeOfArrival, time_t departureTime, time_t arrivalTime,
         Bus *bus, const string &status = "planned");

    Trip(const Trip &oldTrip);

    string getId() const;

    string getDepartureTime() const;

    void setDepartureTime(const time_t &newTime);

    string getArrivalTime() const;

    void setArrivalTime(const time_t &newTame);

    string getPlaceOfDeparture() const;

    string getPlaceOfArrival() const;

    string getStatus() const;

    Bus *getBus() const;

    void setStatus(const string &newStatus);

    static void printTripsInfo(const std::vector<Trip> &trips);

    static void printTripInfo(const Trip *trip);

    Status returnStatus(const string &status);

    ~Trip();

};


#endif //BUS_RESEVATION_SYSTEM_TRIP_H
