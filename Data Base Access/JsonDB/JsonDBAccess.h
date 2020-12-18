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
private:
    const static char *tripDirectoryPath;
    const static char *busDirectoryPath;
    const static char *peopleDirectoryPath;
    const static char *driverDirectoryPath;
public:
    Trip *selectTrip(string idTrip) override;

    vector<Trip> selectTrip(string _placeOfDeparture, string _placeOfArrival) override;

    vector<Trip> selectTrip() override;

    vector<Trip> selectTripForDriver(string driverLicenseNumber) override;

    bool insertTrip(Trip *newTrip) override;

    void deleteTrip(string idTrip) override;

    void updateTrip(string idTrip, Trip newTrip) override;

    People *selectPeople(string passportNum) override; //passport

    bool insertPeople(People *newPeople) override;

    Driver *selectDriver(string idDriver) override; //passport

    bool insertDriver(Driver *newDriver) override;

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

    static void writeInJsonFile(const json &jsn, const char *phat);

    static void readFromJsonFile(json &jsn, const char *phat);
};


#endif //BUS_RESEVATION_SYSTEM_JSONDBACCESS_H
