//
// Created by abmkrtchyan on 10.12.20.
//

#include "../Header/MainFunctions.h"
#include <iostream>
#include "../../Data Base Access/JsonDB/JsonDBAccess.h"

void MainFunctions::beginPrint() {
    printf("\e[1;1H\e[2J");
    printf("%20d.%s \n", 1, "Log in ");
    printf("%20d.%s \n", 2, "Sign up");
    printf("%20d.%s \n", 0, "Exit");
    printf("%2s:-> ", "Choose an option");
}

void MainFunctions::mainOptionsPrint() {
    printf("%41d.%s\n ", 1, "Select a trip");
    printf("%40d.%s\n ", 2, "Reserve seat on the bus");
    printf("%40d.%s\n ", 3, "Become a driver");
    printf("%40d.%s\n ", 0, "Exit");
    printf("%40s:-> ", "Choose an option");
}

People *MainFunctions::logOrReg(int answer) {
    People *people = nullptr;
    switch (answer) {
        case 1:
            people = login();
            break;
        case 2:
            people = signUp();
            break;
        case 0:
            exit(0);
        default:
            while (people == nullptr) {
                printf("%s\n", "Incorrect choice. Please select again");
                std::cin >> answer;
                people = logOrReg(answer);
            }
            break;

    }
    return people;
}

People *MainFunctions::login() {
    printf("\e[1;1H\e[2J");
    printf("%-20s:", " Please, enter your passport number");
    int passportNum;
    std::cin >> passportNum;
    JsonDBAccess dbAccess;
    return dbAccess.selectPeople(passportNum);
}

People *MainFunctions::signUp() {
    string peopleName;
    int passportNumber;
    printf("\e[1;1H\e[2J");
    printf("%s: ", " Please, enter your name");
    std::cin >> peopleName;
    printf("%s: ", " Please, enter your passport number");
    std::cin >> passportNumber;
    auto *people = new People(peopleName, passportNumber);
    JsonDBAccess dbAccess;
    dbAccess.insertPeople(*people);
    return people;
}

void MainFunctions::mainOptions(int answer) {
    switch (answer) {
        case 1: //Select a trip
            selectTrip();
            break;
        case 2: //Reserve seat on the bus
            reserveSeat();
            break;
        case 3: //Become a driver
            becomeDriver();
            break;
        case 0: //Exit
            exit(0);
        default:
            printf("%s\n", "Incorrect choice. Please select again");
            std::cin >> answer;
            mainOptions(answer);
            break;
    }
}

void MainFunctions::selectTrip() {
    printf("\e[1;1H\e[2J If you want to see everything, enter 1, otherwise 0");
    int answer = 0;
    std::cin >> answer;
    if (1 == answer) {
        printTripsInfo();
        return;
    }
    printf("Enter the required information or press \"ENTER\":\n");
    printf("Enter trip ID:-> ");
    printf("Route from:-> ");
    printf("Route to:-> ");
}


void MainFunctions::reserveSeat() {

}

void MainFunctions::becomeDriver() {

}

void MainFunctions::printTripsInfo(vector<Trip> trips) {

}



