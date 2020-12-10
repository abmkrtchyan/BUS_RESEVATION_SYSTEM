//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/People.h"

#include <utility>

People::People() {
    _name = "";
    _id = 0;
}

People::People(string name, int passportNumber) {
    _name = std::move(name);
    _id = passportNumber;
}

People::People(const People &oldPeople) {
    this->_id = oldPeople._id;
    this->_name = oldPeople._name;
}

string People::getName() const {
    return this->_name;
}

void People::setName(string newName) {
    this->_name = std::move(newName);
}


People::~People() = default;
