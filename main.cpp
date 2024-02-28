#include <iostream>
#include "myVector.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    myVector<int> x, y;
    myVector<char> a, b;

    x.push_back(5);
    y.push_back(6);

    a.push_back('a');

    std::cout << x.at(0) << '\n';
    std::cout << x.size() << '\n';

    /* crash the program with an exception */ 
    b.front();

    return 0;
}
