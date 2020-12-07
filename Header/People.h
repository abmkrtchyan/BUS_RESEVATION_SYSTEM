//
// Created by abmkrtchyan on 02.12.20.
//
#include <string>

using std::string;

#ifndef BUS_RESEVATION_SYSTEM_PEOPLE_H
#define BUS_RESEVATION_SYSTEM_PEOPLE_H


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
