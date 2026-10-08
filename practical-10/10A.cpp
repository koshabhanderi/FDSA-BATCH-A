#include <iostream>
using namespace std;

int main() {
    int table[10];

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    int n;
    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter registration numbers: ";

    for (int i = 0; i < n; i++) {
        int number;
        cin >> number;

        int slot = number % 10;
        int start = slot;

        while (table[slot] != -1) {
            slot = (slot + 1) % 10;

            if (slot == start)
                break;
        }

        if (table[slot] == -1)
            table[slot] = number;
        else
            cout << "Parking lot is full. Vehicle " << number << " cannot be parked.\n";
    }

    cout << "\nFinal Parking Slots:\n";

    for (int i = 0; i < 10; i++) {
        cout << "Slot " << i << ": ";

        if (table[i] == -1)
            cout << "Empty";
        else
            cout << table[i];

        cout << endl;
    }

    return 0;
}
