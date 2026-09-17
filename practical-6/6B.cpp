#include <iostream>
using namespace std;

struct Node
{
    string page;
    Node *next;
};

int main()
{
    Node *top = NULL;

    int choice;
    string page;

    while (true)
    {
        cout << "\n1. Visit page";
        cout << "\n2. Back";
        cout << "\n3. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter page: ";
            cin >> page;

            Node *newNode = new Node();

            newNode->page = page;
            newNode->next = top;
            top = newNode;

            cout << "Current page = " << top->page << endl;
        }

        else if (choice == 2)
        {
            if (top == NULL)
            {
                cout << "No history available\n";
            }
            else
            {
                cout << "Going back from: " << top->page << endl;

                Node *temp = top;
                top = top->next;

                delete temp;

                if (top == NULL)
                    cout << "No page left\n";
                else
                    cout << "Current page = " << top->page << endl;
            }
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
