#ifndef DETERMINATE_FINITE_AUTOMATON_GUARD_
#define DETERMINATE_FINITE_AUTOMATON_GUARD_

#include <vector>

#include "State.hpp"

#include "AutomatonException.hpp"
#include "AutomatonStateException.hpp"

// typedef std::vector<std::vector<State>> TransitionTable;

template <typename T> class DeterminateFiniteAutomaton {
    public:
    friend std::ostream & operator<<(std::ostream&, const DeterminateFiniteAutomaton <T> &);
	friend std::istream& operator>>(std::istream &, DeterminateFiniteAutomaton<T> &);
	DeterminateFiniteAutomaton();
	DeterminateFiniteAutomaton(std::vector<T>, std::vector<State>, std::vector<std::vector<State>>, char , std::vector<State>);
	DeterminateFiniteAutomaton(std::vector<std::vector<State>>);
	DeterminateFiniteAutomaton(std::vector<State>);
	

	DeterminateFiniteAutomaton(const DeterminateFiniteAutomaton &);
	~DeterminateFiniteAutomaton();
	DeterminateFiniteAutomaton& operator=(const DeterminateFiniteAutomaton&);
    private:
    std::vector<T> alphabet;
    std::vector<State> states;
	std::vector<std::vector<State>> TransitionTable;
	std::vector<State> FinalState; 
	unsigned countState;
	unsigned countAlphabet; 
};
template <typename T>
std::ostream& operator<<(std::ostream &, const DeterminateFiniteAutomaton<T> &);
template <typename T>
std::istream& operator>>(std::istream &, DeterminateFiniteAutomaton<T> &);
#endif
