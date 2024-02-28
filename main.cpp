#include <iostream>
#include <signal.h>

#include "myVector.h"

static void itest();
static void vtest();
static void anothertest();

bool globl = false; 

void dummy(int) {
    if (globl == false) {
        globl = true; 
        anothertest();
    } else {
        exit(1);
    }
};

int testeverything() __asm("main");
int testeverything() {
    signal(SIGABRT, dummy);

    myVector<int> x, y;
    myVector<char> a, b;
    myVector<int> z(10, 9);

    std::cout << z << '\n';

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

    std::cout << "persisted\n";

    return 0;
}

static void itest() {
    std::cout << "Testing iterator\n";

    myVector<int> a; 
    for (int i = 0; i < 50; ++i)
        a.push_back(i);

    for (int i = 0; i < a.size(); ++i) 
        std::cout << a.at(i) << ' ';
    std::cout << '\n';

    for (VecIterator it = a.begin(); it != a.end(); ++it) 
        std::cout << *it << ' ';
    std::cout << '\n';

    for (int i = 0; i < 25; ++i) 
        a.pop_back();

    for (const auto& it : a) 
        std::cout << it << ' ';
    std::cout << '\n';

    return;
}

static void anothertest() {
    myVector<int> oob; 
    oob.push_back(50); 

    try {
        oob.at(50);
    }
    catch (std::exception& e) {
        std::cout << "Caught another exception: \n";
        std::cout << e.what() << '\n';
    }

    return;
}
