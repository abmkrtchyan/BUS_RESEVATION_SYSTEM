//
// Created by abmkrtchyan on 02.12.20.
//
#include <string>
#include "People.h"
#include "Driver.h"

using std::string;
#ifndef BUS_RESEVATION_SYSTEM_BUS_H
#define BUS_RESEVATION_SYSTEM_BUS_H


class Bus {
    struct Seat {
        int _seatNumber;
        People *_people;
        bool _isFree;

        Seat(int seatNumber = 0, People *people = nullptr) : _seatNumber(seatNumber), _people(people),
                                                             _isFree(true) {};

        Seat(const Seat &oldSeat) {
            this->_isFree = oldSeat._isFree;
            this->_seatNumber = oldSeat._seatNumber;
            this->_people = oldSeat._people;
        }

        ~Seat() { delete _people; };
    };

private:
    string _licensePlate;
    int _freeSeatCount;
    int _numberOfPassengers;
    Seat *_seats;
    Driver *_driver;
    bool _isFree; //bus
public:
    Bus();

    Bus(string licensePlate, int numberOfPassengers, Driver *driver);

    Bus(const Bus &oldBus);

    string getLicensePlate();

    void setLicensePlate(string newPlate);

    int getFreeSeatCount() const;

    void setFreeSeatCount(int newCount);

    int getNumberOfPassengers() const;

    void setNumberOfPassengers(int newCount);

    Driver *getDriver() const;

    void setDriver(const Driver &newDriver);

    bool isFree() const;

    void setFree(bool x);

    void print();

    ~Bus();

    bool reserveSeat(int seatNumber, People *people);
};


#endif //BUS_RESEVATION_SYSTEM_BUS_H
