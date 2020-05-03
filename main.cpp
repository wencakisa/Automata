#include <iostream>

#include "DeterminateFiniteAutomaton.hpp"

int main() {
    try {
        int alphabetType;

        std::cout << "Choose an alphabet type (1 - int, 2 – char): ";
        std::cin >> alphabetType;

        if (alphabetType == 1) {
            DeterminateFiniteAutomaton<int> *automaton = new DeterminateFiniteAutomaton<int>();

            std::cin >> *automaton;
            std::cout << *automaton;
        } else if (alphabetType == 2) {
            DeterminateFiniteAutomaton<char> *automaton = new DeterminateFiniteAutomaton<char>();

            std::cin >> *automaton;
            std::cout << *automaton;
        } else {
            throw std::runtime_error("Unknown alphabet type.");
        }

    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
