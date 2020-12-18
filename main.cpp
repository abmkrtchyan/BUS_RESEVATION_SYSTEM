
#include <fstream>
#include <iomanip>
#include "UserAPI/Header/MainFunctions.h"
#include "BaseClasses/Header/Driver.h"
#include "nlohmann/json.hpp"
#include "Data Base Access/JsonDB/JsonDBAccess.h"


using json = nlohmann::json;

int main() {
    /*   MainFunctions::beginPrint();
       int answer;
       std::cin >> answer;
       people = MainFunctions::logOrReg(answer);
       printf("\e[1;1H\e[2J Hi, %s!\n", people->getName().c_str()); //clean console and greeting
       while (true) {
           MainFunctions::mainOptionsPrint();
       }*/
    JsonDBAccess dbAccess;
    auto people1 = new Driver("ABO", "123456", "78901");
    dbAccess.deleteDriver("7890");

   /* ///////////////////////////////////////////////////////////////

    json j8 = R"( {"cdcd": {
       "op": "replace",
       "path": "/baz",
       "value": "boo"
     }})"_json;
    vector<json> alljSon;
    std::ifstream i("../JsonDB/Trip.json");
    if (i.is_open()) {
        json j;
        i >> j;
        std::cout << j << std::endl;
        *//* while (i.good()) {
          json j;
          i >> j;
          alljSon.push_back(j);
      }*//*
        i.close();
    } else {
        throw std::runtime_error("Cannot open istream file");
    }
    alljSon.push_back(j8);
    std::ofstream o("../JsonDB/Trip.json", std::ofstream ::app);
    if (o.is_open()) {
        o << std::setw(4) <<
          alljSon << std::endl;
        o.close();
    } else {
        throw std::runtime_error("Cannot open file");
    }
*/
}

