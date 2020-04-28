#ifndef DETERMINATE_FINITE_AUTOMATON_GUARD_
#define DETERMINATE_FINITE_AUTOMATON_GUARD_

#include <vector>

#include "State.hpp"

#include "AutomatonException.hpp"
#include "AutomatonStateException.hpp"

// typedef std::vector<std::vector<State>> TransitionTable;

template <typename T> class DeterminateFiniteAutomaton {
    std::vector<T> alphabet;
    std::vector<State> states;
};

#endif
