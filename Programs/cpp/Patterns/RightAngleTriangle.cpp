// *
// **
// ***
// ****

#include <iostream>

int main() {
    int n = 4;
    for (int row = 1; row <= n; row++) {  // Here 4 bcoz number of lines is 4
        // for every row run no. of columns
        // Here no. of columns in each row is equal to the row number.
        for (int col = 1; col <= row; col++) {
            std::cout << "* ";
        }
        // adding newline when a row is printed
        std::cout << std::endl;
    }
}