//
// Created by abmkrtchyan on 09.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H
#define BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H

#include <vector>
#include <cstdio>
#include <iostream>
#include "../../BaseClasses/Header/People.h"
#include "../../BaseClasses/Header/Trip.h"

extern People *people;
using std::vector;

class MainFunctions {
public :
    static void beginPrint();

    static void mainOptionsPrint();

    static People *logOrReg(int answer);

    static People *login();

    static People *signUp();

    static void mainOptions();

    static void selectTrip();

    static void enterTripId();

    static void becomeDriver();

    static void reserveSeat();

    static int chooseSeatNumber();
};

#endif //BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H

