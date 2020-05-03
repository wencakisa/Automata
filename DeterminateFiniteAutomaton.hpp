#ifndef DETERMINATE_FINITE_AUTOMATON_GUARD_
#define DETERMINATE_FINITE_AUTOMATON_GUARD_

#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

#include "State.hpp"

#include "AutomatonException.hpp"
#include "AutomatonStateException.hpp"

#define MAX_STR_LEN 1024

typedef std::vector<std::vector<State>> TransitionTable;

template <typename T> class DeterminateFiniteAutomaton {
public:
    DeterminateFiniteAutomaton() {}

    const State* getStartingState() const {
        for (const State& state : this->states) {
            if (state.getIsStarting()) {
                return &state;
            }
        }

        return nullptr;
    }

    void setStartingState(const char* stateName) {
        const State* startingState = this->getStartingState();

        if (startingState) {
            throw AutomatonException(stateName, startingState->getName(), __LINE__);
        }

        this->getStateByName(stateName).setIsStarting(true);
        this->getStateFromTable(stateName).setIsStarting(true);
    }

    void setFinalState(const char* stateName) {
        this->getStateByName(stateName).setIsFinal(true);
        this->getStateFromTable(stateName).setIsFinal(true);
    }

    std::vector<State> getFinalStates() const {
        std::vector<State> finalStates;

        for (State state: this->states) {
            if (state.getIsFinal()) {
                finalStates.push_back(state);
            }
        }

        return finalStates;
    }

    std::istream& extractDataFromInputStream(std::istream& in) {
        unsigned statesCount = 0;

        std::cout << "Number of states: ";
        std::cin >> statesCount;


        for (size_t i = 0; i < statesCount; i++) {
            char stateName[MAX_STR_LEN];

            std::cout << "State [" << i << "]: ";
            std::cin >> stateName;

            this->states.push_back(State(stateName));
        }

        unsigned symbolsCount = 0;

        std::cout << "Number of symbols: ";
        std::cin >> symbolsCount;

        for (size_t i = 0; i < symbolsCount; i++) {
            T symbol;

            std::cout << "Symbol [" << i << "]: ";
            std::cin >> symbol;

            this->alphabet.push_back(symbol);
        }

        for (size_t stateIndex = 0; stateIndex < statesCount; stateIndex++) {
            std::vector<State> rowStates;

            for (size_t symbolIndex = 0; symbolIndex < symbolsCount; symbolIndex++) {
                char toName[MAX_STR_LEN];

                std::cout << "Transition (" << this->states[stateIndex].getName() << ", " << this->alphabet[symbolIndex] << ") -> ";
                std::cin >> toName;

                rowStates.push_back(State(toName));
            }

            this->transitionTable.push_back(rowStates);
        }

        char startingName[MAX_STR_LEN];

        std::cout << "Starting state: ";
        std::cin >> startingName;

        this->setStartingState(startingName);

        unsigned finalStatesCount = 0;

        std::cout << "Final states count: ";
        std::cin >> finalStatesCount;

        for (size_t i = 0; i < finalStatesCount; i++) {
            char finalName[MAX_STR_LEN];

            std::cout << "Final state [" << i << "]: ";
            std::cin >> finalName;

            this->setFinalState(finalName);
        }

        return in;
    }

    std::ostream& exportDataToOutputStream(std::ostream& out) const {
        out << "States count: " << this->states.size() << std::endl;

        out << "States: ( ";
        for (State state : this->states){
            out << state.getName() << " ";
        }
        out << ")" << std::endl;

        out << "Alphabet count: " << this->alphabet.size() << std::endl;

        out << "Alphabet: ( ";
        for (T symbol : this->alphabet) {
            out << symbol << " ";
        }
        out << ")" << std::endl;

        out << "Transition table: ( ";
        for (std::vector<State> row : this->transitionTable) {
            out << "[ ";

            for (State state : row) {
                out << state.getName() << " ";
            }

            out << "] ";
        }
        out << ")" << std::endl;

        out << "Starting state: ";
        if (this->getStartingState()) {
            out << this->getStartingState()->getName();
        } else {
            out << "N/A";
        }
        out << std::endl;

        std::vector<State> finalStates = this->getFinalStates();
        out << "Final states count: " << finalStates.size() << std::endl;

        out << "Final states: ( ";
        for (State state : finalStates) {
            out << state.getName() << " ";
        }
        out << ")" << std::endl;

        return out;
    }

private:
    std::vector<T> alphabet;
    std::vector<State> states;
    TransitionTable transitionTable;

    State& getStateByName(const char* name) {
        for (State& state : this->states) {
            if (strcmp(state.getName(), name) == 0) {
                return state;
            }
        }

        throw AutomatonStateException(name, __LINE__);
    }

    State& getStateFromTable(const char* name) {
        for (std::vector<State> row : this->transitionTable) {
            std::vector<State>::iterator it = std::find(row.begin(), row.end(), this->getStateByName(name));

            if (it != row.end()) {
                return *it;
            }
        }

        throw AutomatonStateException(name, __LINE__);
    }
};

template <typename T>
std::ostream& operator<<(std::ostream& out, const DeterminateFiniteAutomaton<T> & automaton) {
    return automaton.exportDataToOutputStream(out);
}

template <typename T>
std::istream& operator>>(std::istream& in, DeterminateFiniteAutomaton<T> & automaton) {
    return automaton.extractDataFromInputStream(in);
}

#endif
