
#include <fstream>
#include <iomanip>
#include "UserAPI/Header/MainFunctions.h"
#include "BaseClasses/Header/Driver.h"
#include "nlohmann/json.hpp"
#include "Data Base Access/JsonDB/JsonDBAccess.h"


using json = nlohmann::json;

int main() {
    MainFunctions::beginPrint();
    int answer;
    std::cin >> answer;
    people = MainFunctions::logOrReg(answer);
    printf("\e[1;1H\e[2J Hi, %s!\n", people->getName().c_str()); //clean console and greeting
    while (true) {
        MainFunctions::mainOptionsPrint();
    }
}

