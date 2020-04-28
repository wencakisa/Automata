#include "AutomatonStateException.hpp"

AutomatonStateException::AutomatonStateException(const char* stateName, unsigned line) :
    stateName(stateName),
    line(line)
{
    std::ostringstream output;
    output << "Error on line " << this->line << ": State \"" << this->stateName << "\" does not belong to this automaton";

    this->setMessageFromStream(output);
}
