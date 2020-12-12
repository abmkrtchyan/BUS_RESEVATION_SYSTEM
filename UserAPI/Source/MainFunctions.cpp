//
// Created by abmkrtchyan on 10.12.20.
//

#include "../Header/MainFunctions.h"
#include <iostream>
#include "../../Data Base Access/JsonDB/JsonDBAccess.h"

People *people = nullptr;

void MainFunctions::beginPrint() {
    printf("\e[1;1H\e[2J");
    printf("%20d.%s \n", 1, "Log in ");
    printf("%20d.%s \n", 2, "Sign up");
    printf("%20d.%s \n", 0, "Exit");
    printf("%2s:-> ", "Choose an option");
}

void MainFunctions::mainOptionsPrint() {
    printf("%21d.%s\n ", 1, "Select a trip");
    printf("%20d.%s\n ", 2, "Reserve seat on the bus");
    printf("%20d.%s\n ", 3, "Become a driver");
    printf("%20d.%s\n ", 0, "Exit");
    printf("%20s :-> ", "Choose an option");
    MainFunctions::mainOptions();
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
    printf("%s:", " Please, enter your passport number");
    int passportNum;
    std::cin >> passportNum;
    JsonDBAccess dbAccess;
    return dbAccess.selectPeople(passportNum);
}

People *MainFunctions::signUp() {
    string peopleName;
    string passportNumber;
    printf("\e[1;1H\e[2J");
    printf("%s: ", " Please, enter your name");
    std::cin >> peopleName;
    printf("%s: ", " Please, enter your passport number");
    std::cin >> passportNumber; // Որ string եմ տալիս cin printf սխալ են աշխատում
    people = new People(peopleName, passportNumber);
    JsonDBAccess dbAccess;
    dbAccess.insertPeople(*people);
    return people;
}

void MainFunctions::mainOptions() {
    int answer = 0;
    std::cin >> answer;
    switch (answer) {
        case 1: //Select a trip
            selectTrip();
            break;
        case 2: //Reserve seat on the bus
            enterTripId();
            break;
        case 3: //Become a driver
            becomeDriver();
            break;
        case 0: //Exit
            exit(0);
        default:
            printf("%s\n", "Incorrect choice. Please select again");
            std::cin >> answer;
            mainOptions();
            break;
    }
}

void MainFunctions::selectTrip() {
    printf("\e[1;1H\e[2J If you want to see everything, enter 1, otherwise 0 :-> "); //clean console
    int answer = 0;
    std::cin >> answer;
    JsonDBAccess dbAccess;
    if (1 == answer) {
        Trip::printTripsInfo(dbAccess.selectTrip());
        printf("\n\n\n");
        mainOptionsPrint();
        return;
    }
    printf("\nEnter the required information or enter \"0\":\n");
    printf("Enter trip ID:-> ");
    int tripId = 0;
    std::cin >> tripId;
    printf("Route from:-> ");
    string placeOfDeparture;
    std::cin >> placeOfDeparture;
    printf("Route to:-> ");
    string placeOfArrival;
    std::cin >> placeOfArrival;
    if (tripId > 0)
        Trip::printTripsInfo(dbAccess.selectTrip(tripId));
    else Trip::printTripsInfo(dbAccess.selectTrip(placeOfDeparture, placeOfArrival));
    printf("\n\n\n");
    mainOptionsPrint();
}

void MainFunctions::enterTripId() {
    printf("\e[1;1H\e[2J");
    printf(" %s\n", "1. If you don't know the trip ID, enter 1, to selection ");
    printf(" %s\n", "2. If you know the trip ID, enter 2, to reserve seat");
    printf(" %s\n", "3. Back");
    printf(" %s\n", "0. Exit");
    printf(" %s:-> ", "Choose an option");
    int answer;
    std::cin >> answer;
    switch (answer) {
        case 1:
            selectTrip(); //selection trips
            break;
        case 2:
            reserveSeat();
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            mainOptionsPrint(); //Back
            break;
        case 0:
            exit(0); //Exit
        default:
            printf("%s\n", "Incorrect choice. Please select again");
            answer = 0;
            std::cin >> answer;
            enterTripId();
            break;
    }
}

void MainFunctions::becomeDriver() {

}

void MainFunctions::reserveSeat() {
    printf("\n%s", "Enter trip ID:-> ");
    int answer;
    std::cin >> answer;
    JsonDBAccess dbAccess;
    Trip *trip = dbAccess.selectTrip(answer);
    if (trip != nullptr) {
        Trip::printTripsInfo(trip);
        Bus *bus = trip->getBus();
        bus->print();
        int seatNumber = chooseSeatNumber();
        if (bus->reserveSeat(seatNumber, people)) {
            if (dbAccess.insertTrip(*trip)) {
                printf("\e[1;1H\e[2J");
                printf("\n Seat with number N%d reserved!\n", seatNumber);
                Trip::printTripsInfo(trip);
                bus->print();
            }
        };
    } else {
        printf("\nTrip by id = %d, does not exist\n", answer);
        enterTripId();
    }
}

int MainFunctions::chooseSeatNumber() {
    printf("\n%s-->", "Please select the seat number on the bus:");
    int answer;
    std::cin >> answer;
    printf("\e[1;1H\e[2J");
    printf("1. Confirm your choice of seat N%d on the bus", answer);
    printf("\n2. Select a new trip");
    printf("\n3. Make a new choice");
    printf("\n0. Exit");
    printf("\n%s:-> ", "Choose an option");

    int choice;
    std::cin >> choice;
    while (true) {
        switch (choice) {
            case 1:
                return answer;
            case 2:
                enterTripId();
                return 0;
            case 3:
                return chooseSeatNumber();
            case 0:
                exit(0);
            default:
                printf("%s\n:-->", "Incorrect choice. Please select again");
                std::cin >> choice;
        }
    }
}





