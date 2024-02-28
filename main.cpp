#include <iostream>
#include "myVector.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    myVector<int> x, y;
    myVector<char> a, b;

    std::cout << "Size: " << x.size() << '\n';
    x.push_back(5);
    std::cout << "Size: " << x.size() << '\n';
    x.push_back(7);
    std::cout << "Size: " << x.size() << '\n';
    y.push_back(6);

    a.push_back('a');

    std::cout << x.at(0) << '\n';
    std::cout << "Size: " << x.size() << '\n';

    for (int i = 0; i < x.size(); i++) 
        std::cout << x.at(i) << '\n'; 

    std::cout << "This\n";
    x.pop_back(); 
    for (int i = 0; i < x.size(); i++) 
        std::cout << x.at(i) << '\n'; 

    /* crash the program with an exception */ 
    b.front();

    return 0;
}
