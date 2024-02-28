#include <iostream>

#include "myVector.h"

static void itest();
static void vtest();

int main() {
    myVector<int> x, y;
    myVector<char> a, b;

    x.push_back(5);
    x.push_back(7);
    y.push_back(6);

    a.push_back('a');
    a.push_back('b');

    std::cout << x.at(0) << '\n';
    std::cout << "Size: " << x.size() << '\n';

    for (int i = 0; i < x.size(); i++) 
        std::cout << x.at(i) << '\n'; 

    x.pop_back(); 
    for (int i = 0; i < x.size(); i++) 
        std::cout << x.at(i) << '\n'; 

    std::cout << a << '\n';


    itest();
    std::cout << "All tests done. Crashing with exception\n";
    /* crash the program with an exception */ 
    b.front();

    return 0;
}

static void itest() {
    std::cout << "Testing iterator\n";

    myVector<int> a; 
    for (int i = 0; i < 50; ++i)
        a.push_back(i);

    for (int i = 0; i < a.size(); ++i) 
        std::cout << a.at(i) << '\n';

    for (VecIterator it = a.begin(); it != a.end(); ++it) {
        std::cout << *it << '\n';
    }

    for ( const auto& it : a) {
        std::cout << it << '\n';
    }

    return;
}
