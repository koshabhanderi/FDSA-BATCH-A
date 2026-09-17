#include <iostream>
using namespace std;

int main()
{
    int n, choice, value;
    cout<<"enetr the number of plates to be taken";
    cin>>n;

    int stack[n];
    int top = -1;

    while (true)
    {
        cout << "\n1. Place";
        cout << "\n2. Take";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin>>choice;

        if (choice == 1)
        {
            cin>>value;

            if (top == n - 1)
            {
                cout << "Error: Stack is full\n";
            }
            else
            {
                top++;
                stack[top] = value;
                cout << "Top tray = " << stack[top] << endl;
            }
        }

        else if (choice == 2)
        {
            if (top == -1)
            {
                cout << "Error: Stack is empty\n";
            }
            else
            {
                cout << "Taken tray = " << stack[top] << endl;
                top--;

                if (top == -1)
                    cout << "Stack is empty\n";
                else
                    cout << "Top tray = " << stack[top] << endl;
            }
        }

        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}
