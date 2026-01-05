#include "MutantStack.hpp"
#include <iostream>

int main() {
    MutantStack<int> ms;

    // Push some elements
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);

    std::cout << "Iterating with iterator:" << std::endl;
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Iterating with const_iterator:" << std::endl;
    const MutantStack<int>& cms = ms;
    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Test arrow operator if T is a struct, but for int, just deref
    std::cout << "Top element: " << ms.top() << std::endl;

    return 0;
}