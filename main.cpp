#include <iostream>

#include "DeterminateFiniteAutomaton.hpp"

int main() {
    try {
        DeterminateFiniteAutomaton<char> automaton;
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
