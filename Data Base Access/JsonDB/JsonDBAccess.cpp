//
// Created by abmkrtchyan on 09.12.20.
//

#include "JsonDBAccess.h"
#include "../../BaseClasses/Header/Trip.h"
#include <ctime>

//auto it = std::find_if(things.begin(), things.end(), [](const Thing &t) { return t.a == 2; });


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

bool JsonDBAccess::insertTrip(Trip newTrip) {
    return true;
}

void JsonDBAccess::deleteTrip(int idTrip) {

}

void JsonDBAccess::updateTrip(int idTrip, Trip newTrip) {

}

People *JsonDBAccess::selectPeople(string passportNum) {
    People *driver = new Driver("Abo", "1234", "5678");
    return driver;
}

void JsonDBAccess::insertPeople(People newPeople) {
    json people;
}

vector<Driver> JsonDBAccess::selectDriver(string idDriver) {
    return vector<Driver>();
}

bool JsonDBAccess::insertDriver(Driver newDriver) {
    return true;
}

void JsonDBAccess::deleteDriver(string idDriver) {

}

void JsonDBAccess::updateDriver(string idDriver, Driver newDriver) {

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
    return true;
}

void JsonDBAccess::deleteBus(string licensePlateBus) {

}

void JsonDBAccess::updateBus(string licensePlateBus, Bus newBus) {

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
