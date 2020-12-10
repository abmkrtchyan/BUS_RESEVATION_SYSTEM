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
    int _id;//passport
public:
    People();

    People(string name, int passportNumber);

    People(const People &oldPeople);

    virtual string getName() const;

    virtual void setName(string newName);

    virtual ~People();
};


#endif //BUS_RESEVATION_SYSTEM_PEOPLE_H
