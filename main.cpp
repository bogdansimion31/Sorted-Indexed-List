#include <iostream>

#include "ExtendedTest.h"
#include "ShortTest.h"

int main() {
    testAll();
    testAllExtended();
    std::cout << "Finished IL Tests!" << std::endl;
    system("pause");
}