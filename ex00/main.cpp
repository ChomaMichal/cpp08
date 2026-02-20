#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::vector<int>::iterator it = easyfind(vec, 3);
    if (it != vec.end()) {
        std::cout << "Found in vector: " << *it << std::endl;
    } else {
        std::cout << "Not found in vector" << std::endl;
    }

    it = easyfind(vec, 5);
    if (it != vec.end()) {
        std::cout << "Found in vector: " << *it << std::endl;
    } else {
        std::cout << "Not found in vector" << std::endl;
    }

    std::list<int> lst;
    lst.push_back(10);
    lst.push_back(20);
    lst.push_back(30);

    std::list<int>::iterator lit = easyfind(lst, 20);
    if (lit != lst.end()) {
        std::cout << "Found in list: " << *lit << std::endl;
    } else {
        std::cout << "Not found in list" << std::endl;
    }

    lit = easyfind(lst, 25);
    if (lit != lst.end()) {
        std::cout << "Found in list: " << *lit << std::endl;
    } else {
        std::cout << "Not found in list" << std::endl;
    }

    return 0;
}