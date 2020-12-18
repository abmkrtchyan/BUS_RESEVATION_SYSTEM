//
// Created by abmkrtchyan on 09.12.20.
//

#include "JsonDBAccess.h"
#include "../../BaseClasses/Header/Trip.h"
#include <ctime>
#include <fstream>
#include <iomanip>

//auto it = std::find_if(things.begin(), things.end(), [](const Thing &t) { return t.a == 2; });

const char *JsonDBAccess::tripDirectoryPath = "../JsonDB/trip.json";
const char *JsonDBAccess::busDirectoryPath = "../JsonDB/bus.json";
const char *JsonDBAccess::driverDirectoryPath = "../JsonDB/driver.json";
const char *JsonDBAccess::peopleDirectoryPath = "../JsonDB/people.json";

Trip *JsonDBAccess::selectTrip(int idTrip) {

    return nullptr;
}

vector<Trip> JsonDBAccess::selectTrip(string _placeOfDeparture, string _placeOfArrival) {
    return vector<Trip>();
}

vector<Trip> JsonDBAccess::selectTrip(string driverLicenseNumber) {
    return vector<Trip>();
}

vector<Trip> JsonDBAccess::selectTrip() {
    return vector<Trip>();
}

bool JsonDBAccess::insertTrip(Trip *newTrip) {
    json trip{};
    json answer = json::array();
    tripToJson(trip, *newTrip);
    readFromJsonFile(answer, tripDirectoryPath);
    newTrip->setID(newTrip->getDepartureTime() + newTrip->getBus()->getLicensePlate());//set ID for trip
    for (const auto &element : answer) {
        if (element["PASSPORT_ID"] == newTrip->getId())
            return false;
    }
    answer.push_back(trip);
    writeInJsonFile(answer, tripDirectoryPath);
    return true;
}

void JsonDBAccess::deleteTrip(string idTrip) {
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, tripDirectoryPath);
    for (const auto &element : read)
        if (element["ID"] != idTrip)
            answer.push_back(element);
    writeInJsonFile(answer, tripDirectoryPath);
}

void JsonDBAccess::updateTrip(string idTrip, Trip newTrip) {
    json trip{};
    tripToJson(trip, newTrip);
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, tripDirectoryPath);
    for (const auto &element : read)
        if (element["ID"] != idTrip)
            answer.push_back(element);
        else answer.push_back(trip);
    writeInJsonFile(answer, tripDirectoryPath);
}

People *JsonDBAccess::selectPeople(string passportNum) {
    People *driver = new Driver("Abo", "1234", "5678");
    return driver;
}

bool JsonDBAccess::insertPeople(People *newPeople) {
    json people{};
    json answer = json::array();
    peopleToJson(people, *newPeople);
    readFromJsonFile(answer, peopleDirectoryPath);
    for (const auto &element : answer) {
        if (element["PASSPORT_ID"] == newPeople->getPassportId())
            return false;
    }
    answer.push_back(people);
    writeInJsonFile(answer, peopleDirectoryPath);
    return true;
}

vector<Driver> JsonDBAccess::selectDriver(string idDriver) {
    return vector<Driver>();
}

bool JsonDBAccess::insertDriver(Driver *newDriver) {
    json driver{};
    json answer = json::array();
    driverToJson(driver, *newDriver);
    readFromJsonFile(answer, driverDirectoryPath);
    for (const auto &element : answer) {
        if (element["DRIVERS_LICENSE"] == newDriver->getDriversLicense())
            return false;
    }
    answer.push_back(driver);
    writeInJsonFile(answer, driverDirectoryPath);
    return true;
}

void JsonDBAccess::deleteDriver(string idDriver) {
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, driverDirectoryPath);
    for (const auto &element : read)
        if (element["DRIVERS_LICENSE"] != idDriver)
            answer.push_back(element);
    writeInJsonFile(answer, driverDirectoryPath);
}

void JsonDBAccess::updateDriver(string idDriver, Driver newDriver) {
    json driver{};
    driverToJson(driver, newDriver);
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, driverDirectoryPath);
    for (const auto &element : read)
        if (element["DRIVERS_LICENSE"] != idDriver)
            answer.push_back(element);
        else answer.push_back(driver);
    writeInJsonFile(answer, driverDirectoryPath);
}

vector<Bus> JsonDBAccess::selectBus(string licensePlate) {
    return vector<Bus>();
}

vector<Bus> JsonDBAccess::selectBus(int maxNumberOfPassengers, int minNumberOfPassengers) {
    return vector<Bus>();
}

vector<Bus> JsonDBAccess::selectBus(bool freeBuses) {
    return vector<Bus>();
}

bool JsonDBAccess::insertBus(Bus newBus) {
    json bus{};
    json answer = json::array();
    busToJson(bus, newBus);
    readFromJsonFile(answer, busDirectoryPath);
    for (const auto &element : answer) {
        if (element["LICENSE_PLATE"] == newBus.getLicensePlate())
            return false;
    }
    answer.push_back(bus);
    writeInJsonFile(answer, busDirectoryPath);
    return true;

}

void JsonDBAccess::deleteBus(string licensePlateBus) {
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, busDirectoryPath);
    for (const auto &element : read)
        if (element["LICENSE_PLATE"] != licensePlateBus)
            answer.push_back(element);
    writeInJsonFile(answer, busDirectoryPath);
}

void JsonDBAccess::updateBus(string licensePlateBus, Bus newBus) {
    json bus{};
    busToJson(bus, newBus);
    json read = json::array();
    json answer = json::array();
    readFromJsonFile(read, busDirectoryPath);
    for (const auto &element : read)
        if (element["LICENSE_PLATE"] != licensePlateBus)
            answer.push_back(element);
        else answer.push_back(bus);
    writeInJsonFile(answer, busDirectoryPath);
}

void JsonDBAccess::tripToJson(json &jsn, const Trip &trip) {
    jsn = json{{"ID",              trip.getId()},
               {"STATUS",          trip.getStatus()},
               {"DEPARTURE_TIME",  trip.getDepartureTime()},
               {"PLACE_DEPARTURE", trip.getPlaceOfDeparture()},
               {"ARRIVAL_TIME",    trip.getArrivalTime()},
               {"PLACE_ARRIVAL",   trip.getPlaceOfArrival()},
               {"ID_BUS",          trip.getBus()->getLicensePlate()}
    };
}

void JsonDBAccess::peopleToJson(json &jsn, const People &people) {
    jsn = json{{"PASSPORT_ID", people.getPassportId()},
               {"NAME",        people.getName()}
    };
}

void JsonDBAccess::driverToJson(json &jsn, const Driver &driver) {
    jsn = json{{"PASSPORT_ID",     driver.getPassportId()},
               {"NAME",            driver.getName()},
               {"DRIVERS_LICENSE", driver.getDriversLicense()}
    };
}

void JsonDBAccess::busToJson(json &jsn, const Bus &bus) {
    jsn = json{
            {"LICENSE_PLATE",       bus.getLicensePlate()},
            {"NUMBER_OF_PASSENGER", bus.getNumberOfPassengers()},
            {"FREE_SEAT_COUNT",     bus.getFreeSeatCount()},
            {"DRIVERS_LICENSE",     bus.getDriver()->getDriversLicense()},
            {"STATUS",              bus.isFree()},
    };
    jsn["SEAT"] = bus.getSeat();
}

void JsonDBAccess::tripFromJson(const json &jsn, vector<Trip> &tripV) {
    string id;
    time_t departureTime;
    time_t arrivalTime;
    string placeOfDeparture;
    string placeOfArrival;
    Bus *bus;

    string status;
    for (const auto &element : jsn) {
        string departureTimeString;
        string arrivalTimeString;
        string busId;
        element.at("ID").get_to(id);
        element.at("STATUS").get_to(status);
        element.at("DEPARTURE_TIME").get_to(departureTimeString);
        element.at("PLACE_DEPARTURE").get_to(placeOfDeparture);
        element.at("ARRIVAL_TIME").get_to(arrivalTimeString);
        element.at("PLACE_ARRIVAL").get_to(placeOfArrival);
        element.at("ID_BUS").get_to(busId);

        struct std::tm departureTimeInfo{};
        strptime(&departureTimeString[0], "%H:%M %d.%m.%Y", &departureTimeInfo);
        departureTime = mktime(&departureTimeInfo);

        struct std::tm arrivalTimeInfo{};
        strptime(&arrivalTimeString[0], "%H:%M %d.%m.%Y", &arrivalTimeInfo);
        arrivalTime = mktime(&arrivalTimeInfo);

        JsonDBAccess dbAccess;
        bus = &(dbAccess.selectBus(busId).front()); //nullptr?

        Trip *trip = new Trip(id, placeOfDeparture, placeOfArrival, departureTime, arrivalTime, bus, status);
        tripV.push_back(*trip);
    }
}

void JsonDBAccess::peopleFromJson(const json &jsn, vector<People> &peopleV) {
    string name;
    string passportId;//passport

    for (const auto &element : jsn) {
        element.at("NAME").get_to(name);
        element.at("PASSPORT_ID").get_to(passportId);

        peopleV.emplace_back(name, passportId); //peopleV add new element
    }
}

void JsonDBAccess::driverFromJson(const json &jsn, vector<Driver> &driverV) {
    string name;
    string passportId;//passport
    string driversLicense;
    for (const auto &element : jsn) {
        element.at("NAME").get_to(name);
        element.at("PASSPORT_ID").get_to(passportId);
        element.at("DRIVERS_LICENSE").get_to(driversLicense);

        driverV.emplace_back(name, passportId, driversLicense); //driverV add new element
    }
}

void JsonDBAccess::busFromJson(const json &jsn, vector<Bus> &busV) {
    string licensePlate;
    int freeSeatCount;
    int numberOfPassengers;
    Driver *driver;
    bool status; //bus
    std::map<int, std::pair<People *, bool>> seats;
    for (const auto &element : jsn) {
        string driverLicense;
        string arrivalTimeString;
        string busId;
        std::map<int, std::pair<string, bool>> seatsStr;
        element.at("LICENSE_PLATE").get_to(licensePlate);
        element.at("STATUS").get_to(status);
        element.at("NUMBER_OF_PASSENGER").get_to(numberOfPassengers);
        element.at("FREE_SEAT_COUNT").get_to(freeSeatCount);
        element.at("DRIVERS_LICENSE").get_to(driverLicense);
        element.at("SEAT").get_to(seatsStr);

        JsonDBAccess dbAccess;
        for (auto &seat:seatsStr) {
            People *people;
            if (seat.second.first != "NULL")
                people = new People(*dbAccess.selectPeople(seat.second.first));
            else people = nullptr;
            seats.insert(std::pair<int, std::pair<People *, bool>>(seat.first, std::pair<People *, bool>(people,
                                                                                                         seat.second.second)));
        }

        driver = &(dbAccess.selectDriver(driverLicense).front());//nullptr.front()  ?

        Bus *bus = new Bus(licensePlate, freeSeatCount, numberOfPassengers, driver, status, seats);
        busV.push_back(*bus);
    }
}

void JsonDBAccess::readFromJsonFile(json &jsn, const char *phat) {
    std::ifstream i(phat);
    json allJson = {};
    if (i.is_open()) {
        i >> allJson;
        i.close();
    } else {
        throw std::runtime_error("Cannot open istream file: " + string(phat));
    }
    jsn.clear();
    for (const auto &element : allJson) {
        jsn.push_back(element);
    }
}

void JsonDBAccess::writeInJsonFile(const json &jsn, const char *phat) {
    std::ofstream o(phat);
    if (o.is_open()) {
        o << std::setw(4) << jsn << std::endl;
        o.close();
    } else {
        throw std::runtime_error("Cannot open file: " + string(phat));
    }
}