#ifndef CUSTOM_MESSAGE_EXCEPTION_GUARD_
#define CUSTOM_MESSAGE_EXCEPTION_GUARD_

#include <sstream>
#include <exception>

class CustomMessageException : public std::exception {
    char* message;
protected:
    void setMessageFromStream(std::ostringstream&);
public:
    CustomMessageException();

    const char* what() const throw();

    ~CustomMessageException();
};


#endif
