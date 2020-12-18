//
// Created by abmkrtchyan on 08.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_IDATABASEACCESS_H
#define BUS_RESEVATION_SYSTEM_IDATABASEACCESS_H

#include<vector>
#include "../BaseClasses/Header/Bus.h"
#include "../BaseClasses/Header/Driver.h"
#include "../BaseClasses/Header/Trip.h"

using std::vector;

class IDataBaseAccess {
public:
    virtual Trip *selectTrip(string idTrip) = 0;

    virtual vector<Trip> selectTrip(string _placeOfDeparture, string _placeOfArrival = "") = 0;

    virtual vector<Trip> selectTrip() = 0;

    virtual vector<Trip> selectTripForDriver(string driverLicenseNumber) = 0;

    virtual bool insertTrip(Trip *newTrip) = 0;

    virtual void deleteTrip(string idTrip) = 0;

    virtual void updateTrip(string idTrip, Trip newTrip) = 0;

    virtual People *selectPeople(string passportNum) = 0;

    virtual bool insertPeople(People *newPeople) = 0;

    virtual Driver *selectDriver(string idDriver) = 0; //passport

    virtual bool insertDriver(Driver *newDriver) = 0;

    virtual void deleteDriver(string idDriver) = 0;

    virtual void updateDriver(string idDriver, Driver newDriver) = 0;

    virtual vector<Bus> selectBus(string licensePlate) = 0;

    virtual vector<Bus> selectBus(int maxNumberOfPassengers, int minNumberOfPassengers = 0) = 0;

    virtual vector<Bus> selectBus(bool freeBuses) = 0;

    virtual bool insertBus(Bus newBus) = 0;

    virtual void deleteBus(string licensePlateBus) = 0;

    virtual void updateBus(string licensePlateBus, Bus newBus) = 0;

    virtual ~IDataBaseAccess() {};
};


#endif //BUS_RESEVATION_SYSTEM_IDATABASEACCESS_H
