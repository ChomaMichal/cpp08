#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main() {
    // Example from requirements
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    // Test with negatives
    Span sp5(3);
    sp5.addNumber(-10);
    sp5.addNumber(0);
    sp5.addNumber(10);
    std::cout << "Shortest with negatives: " << sp5.shortestSpan() << std::endl;
    std::cout << "Longest with negatives: " << sp5.longestSpan() << std::endl;

    // Test exceptions
    Span sp3(2);
    sp3.addNumber(1);
    sp3.addNumber(2);
    try {
        sp3.addNumber(3);
    } catch (std::exception &e) {
        std::cout << "Exception caught: Span is full" << std::endl;
    }

    Span sp4(1);
    sp4.addNumber(5);
    try {
        sp4.shortestSpan();
    } catch (std::exception &e) {
        std::cout << "Exception caught: Not enough elements for span" << std::endl;
    }

    // Large test with 10,000 numbers
    Span sp2(10000);
    int vec[10000];
    srand(time(NULL));
    for (int i = 0; i < 10000; ++i) {
        vec[i] = rand() % 1000000;
    }
    sp2.addNumbers(vec, vec + 10000);
    std::cout << "Shortest span in 10,000 numbers: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest span in 10,000 numbers: " << sp2.longestSpan() << std::endl;

    return 0;
}