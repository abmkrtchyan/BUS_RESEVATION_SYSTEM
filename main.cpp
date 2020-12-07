#include <iostream>
#include "Header/Driver.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Driver *x = new Driver("Valod", 10, 20);
    std::cout << x->getName() << std::endl;

    struct tm *ptr;
    time_t It;
    It = time(nullptr);
    ptr = localtime(&It);
    printf("%s", asctime(ptr));
    (x->getName() != "Valod") ? (std::cout << 1 << std::endl) : std::cout << 2;
    return 0;
}
