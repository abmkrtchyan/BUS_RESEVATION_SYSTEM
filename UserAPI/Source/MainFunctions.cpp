//
// Created by abmkrtchyan on 10.12.20.
//

#include "../Header/MainFunctions.h"
#include <iostream>
#include "../../Data Base Access/JsonDB/JsonDBAccess.h"
#include <ctime>
#include <iomanip>

People *peopleUser = nullptr;

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

People *MainFunctions::logOrReg(int answer) {
    peopleUser = nullptr;
    switch (answer) {
        case 1:
            peopleUser = login();
            break;
        case 2:
            peopleUser = signUp();
            break;
        case 0:
            exit(0);
        default:
            while (peopleUser == nullptr) {
                printf("%s\n", "Incorrect choice. Please select again");
                std::cin >> answer;
                peopleUser = logOrReg(answer);
            }
            break;

    }
    return peopleUser;
}

People *MainFunctions::login() {
    printf("\e[1;1H\e[2J");
    printf("%s:", " Please, enter your passport number");
    string passportNum;
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
    peopleUser = new People(peopleName, passportNumber);
    JsonDBAccess dbAccess;
    dbAccess.insertPeople(peopleUser);
    return peopleUser;
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
    string tripId;
    std::cin >> tripId;
    printf("Route from:-> ");
    string placeOfDeparture;
    std::cin >> placeOfDeparture;
    printf("Route to:-> ");
    string placeOfArrival;
    std::cin >> placeOfArrival;
    if (tripId != "0" && !tripId.empty())
        Trip::printTripInfo(dbAccess.selectTrip(tripId));
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

void MainFunctions::reserveSeat() {
    printf("\n%s", "Enter trip ID:-> ");
    string answer;
    std::cin >> answer;
    JsonDBAccess dbAccess;
    Trip *trip = dbAccess.selectTrip(answer);
    if (trip != nullptr) {
        Trip::printTripInfo(trip);
        Bus *bus = trip->getBus();
        bus->print();
        int seatNumber = chooseSeatNumber();
        if (bus->reserveSeat(seatNumber, peopleUser)) {
            if (dbAccess.insertTrip(trip)) {
                printf("\e[1;1H\e[2J");
                printf("\n Seat with number N%d reserved!\n", seatNumber);
                Trip::printTripInfo(trip);
                bus->print();
            }
        }
    } else {
        printf("\nTrip by id = %s, does not exist\n", answer.c_str());
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

void MainFunctions::becomeDriver() {
    printf("\e[1;1H\e[2J");
    printf("Pleas enter your driver's license number:--> ");
    string answer;
    std::cin >> answer;
    auto *driver = new Driver(peopleUser->getName(), peopleUser->getPassportId(), answer);
    JsonDBAccess dbAccess;
    if (dbAccess.insertDriver(driver)) {
        peopleUser = driver;
        printDriverTools();
    } else {
        printf("\n%s\n", "The attempt failed, please check the accuracy of the data and try again later");
        mainOptionsPrint();
    }
}

void MainFunctions::printDriverTools() {
    printf("\e[1;1H\e[2J");
    printf("1. %s\n", "Register a new trip.");
    printf("2. %s\n", "Manage registered trips.");
    printf("3. %s\n", "Bask.");
    printf("0. %s\n", "Exit.");
    printf("%s:-> ", "Choose an option");

    driverTools();
}

void MainFunctions::driverTools() {
    int answer;
    while (true) {
        std::cin >> answer;
        switch (answer) {
            case 1:
                registerTrip();
                return;
            case 2:
                showMyTrip();
                return;
            case 3:
                mainOptionsPrint(); //Back
                return;
            case 0:
                exit(0); // Exit
            default:
                printf("%s\n:--> ", "Incorrect choice. Please select again");
                break;
        }
    }
}

void MainFunctions::registerTrip() {
    printf("\e[1;1H\e[2J");
    printf("Enter the bus license plate:--> ");
    string licensePlate;
    std::cin >> licensePlate;
    printf("\nEnter the number of passenger seats:--> ");
    int numPasSeat;
    std::cin >> numPasSeat;

    auto *driver = dynamic_cast<Driver *>(peopleUser);
    Bus *bus = new Bus(licensePlate, numPasSeat, driver);

    printf("\nEnter the name of the starting point of the route:--> ");
    string placeOfDeparture;
    std::cin >> placeOfDeparture;
    printf("\nEnter the name of the destination of the route:--> ");
    string placeOfArrival;
    std::cin >> placeOfArrival;

    printf("\nEnter the start time of the trip in the format 'HH:MM DD.MM.YYYY':--> ");
    struct std::tm timeInfo{};
    std::cin >> std::get_time(&timeInfo, "%H:%M %d.%m.%Y");
    if (std::cin.fail()) {
        std::cout << "\nError reading time\nEnter again:--> ";
        exit(1);
    }
    time_t departureTime = mktime(&timeInfo);

    printf("\nEnter the arrival time of the trip in the format 'HH:MM' DD.MM.YYYY:--> ");
    struct std::tm timeInfo1{};
    std::cin >> std::get_time(&timeInfo1, "%H:%M %d.%m.%Y");
    if (std::cin.fail()) {
        std::cout << "Error reading time\nEnter again:--> ";
        exit(1);

        //std::cin >> std::get_time(&timeInfo, "%H:%M %d.%m.%Y"); // MM:HH DD:MM:YYYY
    }
    time_t arrivalTime = mktime(&timeInfo1);

    Trip *trip = new Trip("NULL", placeOfDeparture, placeOfArrival, departureTime, arrivalTime, bus);
    JsonDBAccess dbAccess;

    if (dbAccess.insertTrip(trip) && dbAccess.insertBus(*bus)) {
        printf("\nTrip registered!\n");
        printDriverTools();
    } else {
        printf("\nRegistration error, please try again.\n");
        std::cin.get();
        printDriverTools();
    }
}

void MainFunctions::showMyTrip() {
    printf("\e[1;1H\e[2J");
    JsonDBAccess dbAccess;
    auto *driver = dynamic_cast<Driver *>(peopleUser);
    vector<Trip> trips = dbAccess.selectTripForDriver(driver->getDriversLicense());
    for (const auto &trip:trips) {
        Trip::printTripInfo(&trip);
        trip.getBus()->printAll();
        printf("\n\n");
    }
}




