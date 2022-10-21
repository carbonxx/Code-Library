// *****
// ****
// ***
// **
// *

#include <iostream>

int main() {
    int n = 5;
    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= n - row + 1; col++) {
            // Here n-row because for r=1 c=(n-1)=4 and r=2 c=(n-2)=3,
            // +1 is for the initial value of col
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}