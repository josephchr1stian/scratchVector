#include <iostream>
#include <vector>
#include "myVector.h"
int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> x, y;
    x.push_back(5);
    y.push_back(6);
    std::cout << x.size();
;
    return 0;
}
