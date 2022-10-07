//     *
//    * *
//   * * *
//  * * * *
// * * * * *
//  * * * *
//   * * *
//    * *
//     *

#include <iostream>

int main() {
    int n = 10;
    for (int row = 1; row <= 2 * n; row++) {
        int no_of_cols = row > n ? 2 * n - row - 1 : row - 1;
        // -1 since my index start from 1
        int no_of_spaces = n - no_of_cols;
        for (int space = 1; space <= no_of_spaces; space++) {
            std::cout << " ";
        }
        for (int col = 0; col <= no_of_cols; col++) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}