#include <iostream>
#include <vector>
#include "myVector.h"
int main() {

    std::vector<int> x, y;
    x.push_back(5);
    y.push_back(6);
    int z = 3;
    myVector<int> jamie;
    jamie.push_back(5);
    //std::cout << x.size();
    //std::cout << jamie;
    return 0;
}
