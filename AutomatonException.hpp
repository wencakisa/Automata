#ifndef AUTOMATON_EXCEPTION_GUARD_
#define AUTOMATON_EXCEPTION_GUARD_

#include "CustomMessageException.hpp"

class AutomatonException : public CustomMessageException {
    const char* oldStateName;
    const char* currentStateName;
    unsigned line;
public:
    AutomatonException(const char* oldStateName, const char* currentStateName, unsigned line);
};

#endif
