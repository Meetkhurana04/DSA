#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";

    cin >> n;
    //5

    for (int i = 1; i <= 2 * n - 1; i++) {
        //  i = 1 ; j<
        int stars = i <= n ? i : 2 * n - i;
        int spaces = n - stars;
        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 0; j < stars - 1; j++) cout << "* ";
        if (stars > 0) cout << "*";
        cout << endl;
    }

    return 0;
}
