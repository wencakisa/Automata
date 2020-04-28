#include "CustomMessageException.hpp"

class AutomatonStateException : public CustomMessageException {
    const char* stateName;
    unsigned line;
public:
    AutomatonStateException(const char* stateName, unsigned line);
};
