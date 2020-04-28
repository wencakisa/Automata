#include "CustomMessageException.hpp"

CustomMessageException::CustomMessageException() : message(nullptr) {}

void CustomMessageException::setMessageFromStream(std::ostringstream& output) {
    const char* message = output.str().c_str();
    size_t message_length = strlen(message);

    this->message = new char[message_length + 1];
    strcpy(this->message, message);
}

const char* CustomMessageException::what() const throw() {
    return this->message;
}

CustomMessageException::~CustomMessageException() {
    if (this->message != nullptr) {
        delete[] this->message;
        this->message = nullptr;
    }
}
