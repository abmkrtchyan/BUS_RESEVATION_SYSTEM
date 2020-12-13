//
// Created by abmkrtchyan on 09.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
#define BUS_RESEVATION_SYSTEM_JSONDBACCESS_H


#include "../IDataBaseAccess.h"
#include "../../BaseClasses/Header/Trip.h"

class JsonDBAccess : public IDataBaseAccess {
public:
    Trip *selectTrip(int idTrip) override;

    vector<Trip> selectTrip(string _placeOfDeparture, string _placeOfArrival) override;

    vector<Trip> selectTrip() override;

    vector<Trip> selectTrip(string driverLicenseNumber) override;

    bool insertTrip(Trip newTrip) override;

    void deleteTrip(int idTrip) override;

    void updateTrip(int idTrip, Trip newTrip) override;

    People *selectPeople(string passportNum) override; //passport

    void insertPeople(People newPeople) override;

    vector<Driver> selectDriver(int idDriver) override; //passport

    bool insertDriver(Driver newDriver) override;

    void deleteDriver(int idDriver) override;

    void updateDriver(int idDriver, Driver newDriver) override;

    vector<Bus> selectBus(int licensePlate) override;

    vector<Bus> selectBus(int maxNumberOfPassengers, int minNumberOfPassengers) override;

    vector<Bus> selectBus(bool freeBuses) override;

    bool insertBus(Bus newBus) override;

    void deleteBus(int licensePlateBus) override;

    void updateBus(int licensePlateBus, Bus newBus) override;

};


#endif //BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
