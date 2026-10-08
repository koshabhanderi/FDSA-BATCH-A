#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes: ";

    for (int i = 0; i < n; i++) {
        int code;
        cin >> code;

        int shelf = code % 10;
        table[shelf].push_back(code);
    }

    cout << "\nFinal Shelf Contents:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Shelf " << i << ": ";

        if (table[i].empty()) {
            cout << "Empty";
        } else {
            for (int code : table[i])
                cout << code << " ";
        }

        cout << endl;
    }

    return 0;
}