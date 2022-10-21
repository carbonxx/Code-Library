#include<bits/stdc++.h>
using namespace std;

auto palidrome(char *str) -> bool {
    int i = 0;
    int j = strlen(str) - 1;
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int main(){
    char str[100];
    cout << "Enter a string: ";
    cin >> str;
    if (palidrome(str)) {
        cout << "The string is a palidrome" << endl;
    } else {
        cout << "The string is not a palidrome" << endl;
    }
    return 0;
}