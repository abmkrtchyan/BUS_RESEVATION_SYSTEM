
#include <fstream>
#include "UserAPI/Header/MainFunctions.h"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

int main() {
    while (peopleUser == nullptr) {
        MainFunctions::beginPrint();
        int answer;
        std::cin >> answer;
        peopleUser = MainFunctions::logOrReg(answer);
    }
    printf("\e[1;1H\e[2J Hi, %s!\n", peopleUser->getName().c_str()); //clean console and greeting
    while (true) {
        MainFunctions::mainOptionsPrint();
    }


}

