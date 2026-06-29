#include <iostream>
#include "maths.h" // Bring in the menu so we can use addNumbers

int main() {
    std::cout << "--- My CMake Calculator ---" << std::endl;
    
    int result = addNumbers(5, 10);
    
    std::cout << "5 + 10 = " << result << std::endl;
    
    return 0;
}