//
// Created by abmkrtchyan on 09.12.20.
//

#ifndef BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H
#define BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H

#include <cstdio>
#include "../../BaseClasses/Header/People.h"


class MainFunctions {
public :
    static void beginPrint();

    static People *logOrReg(int answer);

    static People *login();

    static People *signUp();
};

#endif //BUS_RESEVATION_SYSTEM_MAINFUNCTIONS_H

