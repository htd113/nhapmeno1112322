#include<iostream>
using namespace std;
int  check(int a, int b, int c) {
    if (a < b + c && b < a + c && c < a + b) {
        return 1;
    }
    return 0;
}
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (check(a, b, c)) {
        if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b) {
            cout << a + b + c << endl;
            cout << "vuong";
        }
        else if (a == b && a == c) {
            cout << a + b + c << endl;
            cout << "deu";
        }
        else if (a == b || a == c || b == c) {
            cout << a + b + c << endl;
            cout << "can";
        }
        else {
            cout << a + b + c << endl;
            cout << "thuong";
        }
    }
    else {
        cout << "Invalid";
    }
    return 0;
}