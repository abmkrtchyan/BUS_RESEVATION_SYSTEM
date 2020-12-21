//
// Created by abmkrtchyan on 02.12.20.
//

#include "../Header/People.h"

#include <utility>

People::People() {
    _name = "";
    _passportId = "";
}

People::People(string name, string passportNumber) {
    _name = std::move(name);
    _passportId = std::move(passportNumber);
}

People::People(const People &oldPeople) {
    this->_passportId = oldPeople._passportId;
    this->_name = oldPeople._name;

}

string People::getName() const {
    return this->_name;
}

void People::setName(string newName) {
    this->_name = std::move(newName);
}

string People::getPassportId() const {
    return _passportId;
}

People::~People() = default;
