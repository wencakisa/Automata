#ifndef AUTOMATON_STATE_EXCEPTION_GUARD_
#define AUTOMATON_STATE_EXCEPTION_GUARD_

#include "CustomMessageException.hpp"

class AutomatonStateException : public CustomMessageException {
    const char* stateName;
    unsigned line;
public:
    AutomatonStateException(const char* stateName, unsigned line);
};

#endif
