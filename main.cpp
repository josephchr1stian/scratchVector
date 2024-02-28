#include <iostream>

#include "myVector.h"

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

    std::cout << "All tests done. Crashing with exception\n";
    /* crash the program with an exception */ 
    b.front();

    return 0;
}
