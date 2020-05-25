#ifndef DETERMINATE_FINITE_AUTOMATON_GUARD_
#define DETERMINATE_FINITE_AUTOMATON_GUARD_

#include <vector>
#include <cstring>
#include <fstream>
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

    bool doesRecognizeWord(const T* word) const {
        State currentState = *this->getStartingState();
        size_t wordLength = sizeof(T) / sizeof(word);

        for (size_t letterIndex = 0; letterIndex < wordLength; letterIndex++) {
            T currentLetter = word[letterIndex];
            std::cout << "Current letter: " << currentLetter << std::endl;

            size_t letterInAlphabetIndex = this->vectorIndexOf<T>(this->alphabet, currentLetter);
            size_t currentStateIndex = this->vectorIndexOf<State>(this->states, currentState);

            currentState = this->transitionTable[currentStateIndex][letterInAlphabetIndex];
        }

        return currentState.getIsFinal();
    }

    std::istream& extractDataFromInputStream(std::istream& in) {
        unsigned statesCount = 0;

        std::cout << "Number of states: ";
        in >> statesCount;


        for (size_t i = 0; i < statesCount; i++) {
            char stateName[MAX_STR_LEN];

            std::cout << "State [" << i << "]: ";
            in >> stateName;

            this->states.push_back(State(stateName));
        }

        unsigned symbolsCount = 0;

        std::cout << "Number of symbols: ";
        in >> symbolsCount;

        for (size_t i = 0; i < symbolsCount; i++) {
            T symbol;

            std::cout << "Symbol [" << i << "]: ";
            in >> symbol;

            this->alphabet.push_back(symbol);
        }

        for (size_t stateIndex = 0; stateIndex < statesCount; stateIndex++) {
            std::vector<State> rowStates;

            for (size_t symbolIndex = 0; symbolIndex < symbolsCount; symbolIndex++) {
                char toName[MAX_STR_LEN];

                std::cout << "Transition (" << this->states[stateIndex].getName() << ", " << this->alphabet[symbolIndex] << ") -> ";
                in >> toName;

                rowStates.push_back(State(toName));
            }

            this->transitionTable.push_back(rowStates);
        }

        char startingName[MAX_STR_LEN];

        std::cout << "Starting state: ";
        in >> startingName;

        this->setStartingState(startingName);

        unsigned finalStatesCount = 0;

        std::cout << "Final states count: ";
        in >> finalStatesCount;

        for (size_t i = 0; i < finalStatesCount; i++) {
            char finalName[MAX_STR_LEN];

            std::cout << "Final state [" << i << "]: ";
            in >> finalName;

            this->setFinalState(finalName);
        }

        return in;
    }

    std::ostream& exportDataToOutputStream(std::ostream& out) const {
        out << this->states.size();

        for (State state : this->states){
            out << " " << state.getName();
        }

        out << std::endl;

        // ------------------------------------------------------------

        out << this->alphabet.size();

        for (T symbol : this->alphabet) {
            out << " " << symbol;
        }

        out << std::endl;

        // ------------------------------------------------------------

        for (std::vector<State> row : this->transitionTable) {
            for (State state : row) {
                out << state.getName() << " ";
            }

            out << std::endl;
        }

        // ------------------------------------------------------------

        out << this->getStartingState()->getName();

        out << std::endl;

        // ------------------------------------------------------------

        std::vector<State> finalStates = this->getFinalStates();

        out << finalStates.size();

        for (State state : finalStates) {
            out << " " << state.getName();
        }

        out << std::endl;

        // ------------------------------------------------------------

        return out;
    }

    std::ifstream& extractDataFromFile(std::ifstream& in) {
        unsigned statesCount = 0;

        in >> statesCount;

        for (size_t i = 0; i < statesCount; i++) {
            char stateName[MAX_STR_LEN];

            in >> stateName;

            this->states.push_back(State(stateName));
        }

        unsigned symbolsCount = 0;

        in >> symbolsCount;

        for (size_t i = 0; i < symbolsCount; i++) {
            T symbol;

            in >> symbol;

            this->alphabet.push_back(symbol);
        }

        for (size_t stateIndex = 0; stateIndex < statesCount; stateIndex++) {
            std::vector<State> rowStates;

            for (size_t symbolIndex = 0; symbolIndex < symbolsCount; symbolIndex++) {
                char toName[MAX_STR_LEN];

                in >> toName;

                rowStates.push_back(State(toName));
            }

            this->transitionTable.push_back(rowStates);
        }

        char startingName[MAX_STR_LEN];

        in >> startingName;

        this->setStartingState(startingName);

        unsigned finalStatesCount = 0;

        in >> finalStatesCount;

        for (size_t i = 0; i < finalStatesCount; i++) {
            char finalName[MAX_STR_LEN];

            in >> finalName;

            this->setFinalState(finalName);
        }

        return in;
    }

private:
    std::vector<T> alphabet;
    std::vector<State> states;
    TransitionTable transitionTable;

    template <class N>
    int vectorIndexOf(std::vector<N> v, N element) const {
        for (size_t i = 0; i < v.size(); i++) {
            if (v[i] == element) {
                return i;
            }
        }

        return -1;
    }

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
            auto it = std::find(row.begin(), row.end(), this->getStateByName(name));

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

template <typename T>
std::ifstream& operator>>(std::ifstream& in, DeterminateFiniteAutomaton<T> & automaton) {
    return automaton.extractDataFromFile(in);
}

#endif
