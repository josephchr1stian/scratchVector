#include <iostream>
#include <vector>
#include "myVector.h"
int main() {
    myVector<int> jamie;
    std::vector<int> x, y;
    x.push_back(5);
    y.push_back(6);
    int z = 3;
    jamie.push_back(5);
    std::cout << jamie.at(0) << "\n";
    return 0;
}
