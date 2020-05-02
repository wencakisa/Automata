#include"DeterminateFiniteAutomaton.h"

template<typename T>
DeterminateFiniteAutomaton<T>::DeterminateFiniteAutomaton()
{

}
template<typename T>
DeterminateFiniteAutomaton<T>::DeterminateFiniteAutomaton(std::vector<T> alphabet, std::vector<State> states, std::vector<std::vector<State>> transition, char firstState, std::vector<State> finalState):firstState(firstState)
{

}
template<typename T>
DeterminateFiniteAutomaton<T> :: DeterminateFiniteAutomaton(std::vector<std::vector<State>> transition){}
template<typename T>
DeterminateFiniteAutomaton<T>::DeterminateFiniteAutomaton(std::vector<State> states){}
template<typename T>
DeterminateFiniteAutomaton<T>::DeterminateFiniteAutomaton(std::vector<State> states){}
template<typename T>
DeterminateFiniteAutomaton<T>::DeterminateFiniteAutomaton(const DeterminateFiniteAutomaton & rhs)
{}
template<typename T>
DeterminateFiniteAutomaton<T>::~DeterminateFiniteAutomaton(){}
template<typename T>
DeterminateFiniteAutomaton<T>& DeterminateFiniteAutomaton<T>:: operator=(const DeterminateFiniteAutomaton<T> & rhs){}
template<typename T>
char DeterminateFiniteAutomaton<T>::getFirstState() 
{
	return this->firstState;
}
template <typename T>
unsigned DeterminateFiniteAutomaton<T>::getCountState()
{
	return this->countState;
}
template <typename T>
unsigned DeterminateFiniteAutomaton<T>::getCountAlphabet()
{
	return this->countAlphabet;
}

template<typename T>
std::ostream& operator<<(std::ostream & out, const  DeterminateFiniteAutomaton <T> & rhs)
{

}
template <typename T>
std::istream& operator>>(std::istream & in, DeterminateFiniteAutomaton<T> & rhs)
{

}
