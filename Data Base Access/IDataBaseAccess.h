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
    virtual Trip *selectTrip(int idTrip) = 0;

    virtual vector<Trip> selectTrip(string _placeOfDeparture, string _placeOfArrival = "") = 0;

    virtual vector<Trip> selectTrip() = 0;

    virtual vector<Trip> selectTrip(string driverLicenseNumber) = 0;

    virtual bool insertTrip(Trip newTrip) = 0;

    virtual void deleteTrip(int idTrip) = 0;

    virtual void updateTrip(int idTrip, Trip newTrip) = 0;

    virtual People *selectPeople(string passportNum) = 0;

    virtual void insertPeople(People newPeople) = 0;

    virtual vector<Driver> selectDriver(int idDriver = 0) = 0; //passport

    virtual bool insertDriver(Driver newDriver) = 0;

    virtual void deleteDriver(int idDriver) = 0;

    virtual void updateDriver(int idDriver, Driver newDriver) = 0;

    virtual vector<Bus> selectBus(int licensePlate) = 0;

    virtual vector<Bus> selectBus(int maxNumberOfPassengers, int minNumberOfPassengers = 0) = 0;

    virtual vector<Bus> selectBus(bool freeBuses) = 0;

    virtual bool insertBus(Bus newBus) = 0;

    virtual void deleteBus(int licensePlateBus) = 0;

    virtual void updateBus(int licensePlateBus, Bus newBus) = 0;

    virtual ~IDataBaseAccess() {};
};


#endif //BUS_RESEVATION_SYSTEM_IDATABASEACCESS_H
