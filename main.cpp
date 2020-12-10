#include "iostream"
#include "UserAPI/Header/MainFunctions.h"

int main() {
    MainFunctions::beginPrint();
    int answer;
    std::cin >> answer;
    People *people = MainFunctions::logOrReg(answer);

    printf("Hi, %s!\n", people->getName().c_str());
    return 0;
}
