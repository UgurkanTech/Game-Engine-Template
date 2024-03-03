#include <iostream>
#include "core.h"

int main(int argc, char* argv[]) {
    std::cout << "Hi from runtime!" << std::endl;

    // Call the Exec function
    int result = Exec();

    return 0;
}