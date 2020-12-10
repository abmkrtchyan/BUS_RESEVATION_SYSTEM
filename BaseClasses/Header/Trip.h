//
// Created by abmkrtchyan on 03.12.20.
//
#include <string>
#include <time.h>
#include "Bus.h"

using std::string;
#ifndef BUS_RESEVATION_SYSTEM_TRIP_H
#define BUS_RESEVATION_SYSTEM_TRIP_H


class Trip {
    enum Status {
        planned, inProgress, finished
    };
private:
    int _id = 0;
    time_t _departureTime;
    time_t _arrivalTime;
    string _placeOfDeparture;
    string _placeOfArrival;
    Bus _bus;
    Status _status;
public:
    Trip();

    Trip(int id, string placeOfDeparture, string placeOfArrival, time_t departureTime, time_t arrivalTime,
         const Bus &bus);

    Trip(const Trip &oldTrip);

    int getId() const;

    time_t getDepartureTime() const;

    void setDepartureTime(const time_t &newTime);

    time_t getArrivalTime() const;

    void setArrivalTime(const time_t &newTame);

    string getPlaceOfDeparture() const;

    string getPlaceOfArrival() const;

    void changeStatus();

    ~Trip();

};


#endif //BUS_RESEVATION_SYSTEM_TRIP_H
