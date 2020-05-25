#include <iostream>

#include "DeterminateFiniteAutomaton.hpp"

#define OUTPUT_FILENAME "output.txt"

int main() {
    try {
        int alphabetType;

        std::cout << "Choose an alphabet type (1 - int, 2 – char): ";
        std::cin >> alphabetType;

        if (alphabetType == 1) {
            DeterminateFiniteAutomaton<int> *automaton = new DeterminateFiniteAutomaton<int>();

            // ------------------------------------------------------------
            // File input (uncomment if you want to use it)
            // ------------------------------------------------------------

            // std::ifstream in(OUTPUT_FILENAME);

            // in >> *automaton;
            // std::cout << *automaton;

            // in >> alphabetType;
            // // Validate that the type in the file corresponds to the automaton type
            // if (alphabetType == 1){
            //     in >> *automaton;
            // }
            // std::cout << *automaton;

            // ------------------------------------------------------------
            // Standard I/O
            // ------------------------------------------------------------

            std::cin >> *automaton;
            std::cout << *automaton;

            // ------------------------------------------------------------
            // Word recognition
            // ------------------------------------------------------------

            int word_int;
            std::cout << "Give me a word to recognize: ";
            std::cin >> word_int;

            int word[MAX_STR_LEN];
            size_t i = 0;

            while (word_int > 0) {
                word[i++] = word_int % 10;
                word_int /= 10;
            }

            std::cout << "Word recognized: " << std::boolalpha << automaton->doesRecognizeWord(word) << std::endl;

            // ------------------------------------------------------------
            // File output
            // ------------------------------------------------------------

            std::ofstream out(OUTPUT_FILENAME);
            out << *automaton;
            out.close();
        } else if (alphabetType == 2) {
            DeterminateFiniteAutomaton<char> *automaton = new DeterminateFiniteAutomaton<char>();

            // ------------------------------------------------------------
            // File input (uncomment if you want to use it)
            // ------------------------------------------------------------

            // std::ifstream in(OUTPUT_FILENAME);

            // in >> *automaton;
            // std::cout << *automaton;

            // in >> alphabetType;
            // // Validate that the type in the file corresponds to the automaton type
            // if (alphabetType == 2){
            //     in >> *automaton;
            // }
            // std::cout << *automaton;

            // ------------------------------------------------------------
            // Standard I/O
            // ------------------------------------------------------------

            std::cin >> *automaton;
            std::cout << *automaton;

            // ------------------------------------------------------------
            // Word recognition
            // ------------------------------------------------------------

            char word[MAX_STR_LEN];
            std::cout << "Give me a word to recognize: ";
            std::cin >> word;

            std::cout << "Word recognized: " << std::boolalpha << automaton->doesRecognizeWord(word) << std::endl;

            // ------------------------------------------------------------
            // File output
            // ------------------------------------------------------------

            std::ofstream out(OUTPUT_FILENAME);
            out << *automaton;
            out.close();
        } else {
            throw std::runtime_error("Unknown alphabet type.");
        }
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}
