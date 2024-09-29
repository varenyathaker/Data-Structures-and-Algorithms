#include <iostream>
#include <string>
using namespace std;

void rev_str(string &s, int l, int r) {
    if (l >= r) return;
    swap(s[l], s[r]);
    rev_str(s, l + 1, r - 1);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    rev_str(str, 0, str.length() - 1);
    cout << "Reversed: " << str << endl;
    return 0;
}
