//
// Created by abmkrtchyan on 09.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
#define BUS_RESEVATION_SYSTEM_JSONDBACCESS_H


#include "../IDataBaseAccess.h"
#include "../../BaseClasses/Header/Trip.h"

class JsonDBAccess : public IDataBaseAccess {
public:
    virtual Trip *selectTrip(int idTrip);

    virtual vector<Trip> selectTrip(string _placeOfDeparture, string _placeOfArrival = "");

    virtual vector<Trip> selectTrip();

    virtual bool insertTrip(Trip newTrip);

    virtual void deleteTrip(int idTrip);

    virtual void updateTrip(int idTrip, Trip newTrip);

    People *selectPeople(int passportNum) override; //passport

    virtual void insertPeople(People newPeople);

    vector<Driver> selectDriver(int idDriver) override; //passport

    void insertDriver(Driver newDriver) override;

    virtual void deleteDriver(int idDriver);

    virtual void updateDriver(int idDriver, Driver newDriver);

    virtual vector<Bus> selectBus(int licensePlate);

    virtual vector<Bus> selectBus(int maxNumberOfPassengers, int minNumberOfPassengers = 0);

    virtual vector<Bus> selectBus(bool freeBuses);

    virtual bool insertBus(Bus newBus);

    virtual void deleteBus(int licensePlateBus);

    virtual void updateBus(int licensePlateBus, Bus newBus);


};


#endif //BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
