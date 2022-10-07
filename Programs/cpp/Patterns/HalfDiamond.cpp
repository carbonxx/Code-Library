// *
// * *
// * * *
// * * * *
// * * * * *
// * * * *
// * * *
// * *
// *

#include <iostream>

int main() {
    int n = 9;
    for (int row = 1; row <= n; row++) {
        if (row <= (n / 2) + 1) {  // row ranging from 1 to 5
            for (int col = 1; col <= row; col++) {
                std::cout << "* ";
            }
        } else {  // row ranging from 6 to 9
            for (int col = 1; col <= n - row + 1; col++) {
                std::cout << "* ";
            }
        }
        std::cout << std::endl;
    }
}