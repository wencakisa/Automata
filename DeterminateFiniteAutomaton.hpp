#ifndef DETERMINATE_FINITE_AUTOMATON_GUARD_
#define DETERMINATE_FINITE_AUTOMATON_GUARD_

#include <vector>

#include "State.hpp"

#include "AutomatonException.hpp"
#include "AutomatonStateException.hpp"

typedef std::vector<std::vector<State>> TransitionTable;

template <typename T> class DeterminateFiniteAutomaton {
public:
	friend std::ostream & operator<<(std::ostream&, const DeterminateFiniteAutomaton <T> &);
	friend std::istream& operator>>(std::istream &, DeterminateFiniteAutomaton<T> &);

	DeterminateFiniteAutomaton();
	DeterminateFiniteAutomaton(const DeterminateFiniteAutomaton &);
	DeterminateFiniteAutomaton(std::vector<T>, std::vector<State>, TransitionTable, char, std::vector<State>);
	DeterminateFiniteAutomaton(TransitionTable);
	DeterminateFiniteAutomaton(std::vector<State>);

	~DeterminateFiniteAutomaton();

	DeterminateFiniteAutomaton& operator=(const DeterminateFiniteAutomaton &);

private:
	std::vector<T> alphabet;
	std::vector<State> states;

	TransitionTable transitionTable;
	std::vector<State> finalStates;

	unsigned countState;
	unsigned countAlphabet;
};

template <typename T>
std::ostream& operator<<(std::ostream &, const DeterminateFiniteAutomaton<T> &);

template <typename T>
std::istream& operator>>(std::istream &, DeterminateFiniteAutomaton<T> &);

#endif
