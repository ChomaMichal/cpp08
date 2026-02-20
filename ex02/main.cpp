#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  std::cout << "===== SUBJECT EXAMPLE =====" << std::endl;
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
    std::stack<int> s(mstack);
  }

  std::cout << "\n===== BASIC OPERATIONS =====" << std::endl;
  {
    MutantStack<int> ms;
    ms.push(10);
    ms.push(20);
    ms.push(30);

    std::cout << "Top: " << ms.top() << std::endl;
    std::cout << "Size: " << ms.size() << std::endl;

    ms.pop();
    std::cout << "After pop - Top: " << ms.top() << std::endl;
    std::cout << "After pop - Size: " << ms.size() << std::endl;
  }

  std::cout << "\n===== ITERATOR OPERATIONS =====" << std::endl;
  {
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    ms.push(4);
    ms.push(5);

    std::cout << "Forward iteration: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Backward with -- operator: ";
    MutantStack<int>::iterator it = ms.end();
    --it;
    while (it != ms.begin()) {
      std::cout << *it << " ";
      --it;
    }
    std::cout << *ms.begin() << std::endl;
  }

  std::cout << "\n===== CONST ITERATOR =====" << std::endl;
  {
    MutantStack<int> ms;
    ms.push(100);
    ms.push(200);
    ms.push(300);

    const MutantStack<int> &cms = ms;
    std::cout << "Const iteration: ";
    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end();
         ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\n===== COPY TO STD::STACK =====" << std::endl;
  {
    MutantStack<int> ms;
    ms.push(42);
    ms.push(84);
    ms.push(126);

    std::stack<int> s(ms);
    std::cout << "Copied to std::stack, top: " << s.top() << std::endl;
    std::cout << "Original size: " << ms.size() << std::endl;
    std::cout << "Copy size: " << s.size() << std::endl;
  }

  std::cout << "\n===== COMPARISON WITH STD::LIST =====" << std::endl;
  {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    std::cout << "MutantStack iteration: ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end();
         ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::cout << "std::list iteration: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
      std::cout << *it << " ";
    }
    std::cout << std::endl;
  }

  std::cout << "\n===== EMPTY STACK =====" << std::endl;
  {
    MutantStack<int> ms;
    std::cout << "Empty stack size: " << ms.size() << std::endl;
    std::cout << "Begin == End: " << (ms.begin() == ms.end()) << std::endl;
  }

  std::cout << "\n===== SINGLE ELEMENT =====" << std::endl;
  {
    MutantStack<int> ms;
    ms.push(9999);
    std::cout << "Single element: " << *ms.begin() << std::endl;
    std::cout << "Size: " << ms.size() << std::endl;
  }

  return 0;
}
