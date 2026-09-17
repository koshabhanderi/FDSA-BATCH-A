#include <iostream>
using namespace std;

struct Node
{
    string name;
    Node *prev;
    Node *next;
};

int main()
{
    Node *head = NULL;

    int choice;
    string name;

    while (true)
    {
        cout << "\n1. Join";
        cout << "\n2. Leave";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cin >> name;

            Node *newNode = new Node;
            newNode->name = name;

            if (head == NULL)
            {
                head = newNode;
                newNode->next = head;
                newNode->prev = head;
            }
            else
            {
                Node *last = head->prev;

                newNode->next = head;
                newNode->prev = last;

                last->next = newNode;
                head->prev = newNode;
            }
        }

        else if (choice == 2)
        {
            cin >> name;

            if (head == NULL)
            {
                cout << "Circle is empty\n";
            }
            else
            {
                Node *temp = head;

                do
                {
                    if (temp->name == name)
                        break;

                    temp = temp->next;
                }
                while (temp != head);

                if (temp->name != name)
                {
                    cout << "Student not found\n";
                }
                else if (temp->next == temp)
                {
                    head = NULL;
                    delete temp;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                        head = temp->next;

                    delete temp;
                }
            }
        }

        else if (choice == 3)
        {
            if (head == NULL)
            {
                cout << "Circle is empty\n";
            }
            else
            {
                Node *temp = head;

                do
                {
                    cout << temp->name << " ";
                    temp = temp->next;
                }
                while (temp != head);

                cout << endl;
            }
        }

        else if (choice == 4)
        {
            break;
        }
    }

    return 0;
}
