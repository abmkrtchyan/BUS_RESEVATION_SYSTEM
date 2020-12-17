//
// Created by abmkrtchyan on 09.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
#define BUS_RESEVATION_SYSTEM_JSONDBACCESS_H


#include "../IDataBaseAccess.h"
#include "../../BaseClasses/Header/Trip.h"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

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

    vector<Driver> selectDriver(string idDriver) override; //passport

    bool insertDriver(Driver newDriver) override;

    void deleteDriver(string idDriver) override;

    void updateDriver(string idDriver, Driver newDriver) override;

    vector<Bus> selectBus(string licensePlate) override;

    vector<Bus> selectBus(int maxNumberOfPassengers, int minNumberOfPassengers) override;

    vector<Bus> selectBus(bool freeBuses) override;

    bool insertBus(Bus newBus) override;

    void deleteBus(string licensePlateBus) override;

    void updateBus(string licensePlateBus, Bus newBus) override;

    static void tripToJson(json &jsonFile, const Trip &trip);

    static void peopleToJson(json &jsonFile, const People &people);

    static void driverToJson(json &jsonFile, const Driver &driver);

    static void busToJson(json &jsonFile, const Bus &bus);

    static void tripFromJson(const json &jsonFile, vector<Trip> &tripV);

    static void peopleFromJson(const json &jsonFile, vector<People> &peopleV);

    static void driverFromJson(const json &jsonFile, vector<Driver> &driverV);

    static void busFromJson(const json &jsonFile, vector<Bus> &busV);

};


#endif //BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
