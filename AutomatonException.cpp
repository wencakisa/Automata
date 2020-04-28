#include "AutomatonException.hpp"

AutomatonException::AutomatonException(const char* oldStateName, const char* currentStateName, unsigned line) :
    oldStateName(oldStateName),
    currentStateName(currentStateName),
    line(line)
{
    std::ostringstream output;
    output <<
        "Error on line " << this->line <<
        ": Automaton already has a starting state \"" << this->oldStateName <<
        "\" and you cannot set it to \"" << this->currentStateName << "\"";

    this->setMessageFromStream(output);
}
