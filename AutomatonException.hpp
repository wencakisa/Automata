#include "CustomMessageException.hpp"

class AutomatonException : public CustomMessageException {
    const char* oldStateName;
    const char* currentStateName;
    unsigned line;
public:
    AutomatonException(const char* oldStateName, const char* currentStateName, unsigned line);
};
