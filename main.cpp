
#include <fstream>
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

/*
    ///////////////////////////////////////////////////////////////

    json j8 = R"([
  { "op": "replace", "path": "/baz", "value": "boo" },
  { "op": "add", "path": "/hello", "value": ["world"] },
  { "op": "remove", "path": "/foo"}
])"_json;

    std::ofstream o("../JsonDB/Trip.json");
    if (o.is_open()) {
        o << j8 << std::endl;
        o.close();
    } else {
        throw std::runtime_error("Cannot open file");
    }
    vector<json> alljSon;
    std::ifstream i("../JsonDB/Trip.json");
    if (i.is_open()) {
        std::cout << "123";
        json j;
        i >> j;
        alljSon.push_back(j);
        *//*while (i.good()) {
            json j;
            i >> j;
            alljSon.push_back(j);
        }*//*
        i.close();
    } else {
        throw std::runtime_error("Cannot open istream file");
    }*/
    string s = "xsxxsxsx";
    char *ss = &s[0];
    std::cout << ss;
    vector<string> v;
}

