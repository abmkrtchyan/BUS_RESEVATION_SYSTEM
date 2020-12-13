//
// Created by abmkrtchyan on 02.12.20.
//
#ifndef BUS_RESEVATION_SYSTEM_PEOPLE_H
#define BUS_RESEVATION_SYSTEM_PEOPLE_H

#include <string>

using std::string;

class People {
private:
    string _name;
    string _passportId;//passport
public:
    People();

    People(string name, string passportNumber);

    People(const People &oldPeople);

    virtual string getName() const;

    virtual void setName(string newName);

    virtual string getPassportId() const;

    virtual ~People();
};


#endif //BUS_RESEVATION_SYSTEM_PEOPLE_H
