//
// Created by abmkrtchyan on 10.12.20.
//

#include "../Header/MainFunctions.h"
#include <iostream>
#include "../../Data Base Access/JsonDB/JsonDBAccess.h"

void MainFunctions::beginPrint() {
    printf("\e[1;1H\e[2J");
    printf("%s:\n", "Choose an option");
    printf("%17d.%s \n", 1, "Log in ");
    printf("%17d.%s \n\n", 2, "Sign up");
    printf("%17d.%s \n", 0, "Exit");
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
    People *people = new People(peopleName, passportNumber);
    JsonDBAccess dbAccess;
    dbAccess.insertPeople(*people);
    return people;
}

