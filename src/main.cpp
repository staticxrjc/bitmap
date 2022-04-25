#include <iostream>
#include <generic.h>

int main() {
    std::cout << "Hello World!" << std::endl;
    generic *a = new generic();
    delete a;
}