#include "iostream"
#include "UserAPI/Header/MainFunctions.h"
#include "BaseClasses/Header/Driver.h"


int main() {
    MainFunctions::beginPrint();
    int answer;
    std::cin >> answer;
    people = MainFunctions::logOrReg(answer);
    printf("\e[1;1H\e[2J Hi, %s!\n", people->getName().c_str()); //clean console and greeting
    while (true) {
        MainFunctions::mainOptionsPrint();
        People *driver = new Driver("Abo", "1234", "5678");
    return 0;
}
    }

