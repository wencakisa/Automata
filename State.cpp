#include <cstring>

#include "State.hpp"

State::State(const char* name) : isStarting(false), isFinal(false) {
    size_t name_length = strlen(name);

    this->name = new char[name_length + 1];
    strcpy(this->name, name);
}

const char* State::getName() const {
    return this->name;
}

bool State::getIsStarting() const {
    return this->isStarting;
}

bool State::getIsFinal() const {
    return this->isFinal;
}

void State::setIsStarting(bool value) {
    this->isStarting = value;
}

void State::setIsFinal(bool value) {
    this->isFinal = value;
}

bool State::operator==(const State& other) const {
    return this != &other && strcmp(this->getName(), other.getName()) == 0;
}
