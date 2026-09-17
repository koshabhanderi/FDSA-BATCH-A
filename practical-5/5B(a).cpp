#include <iostream>
using namespace std;

struct Node
{
    string name;
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
            }
            else
            {
                Node *temp = head;

                while (temp->next != head)
                    temp = temp->next;

                temp->next = newNode;
                newNode->next = head;
            }
        }

        else if (choice == 2)
        {
            cin >> name;

            if (head == NULL)
            {
                cout << "Circle is empty\n";
            }
            else if (head->name == name)
            {
                Node *temp = head;

                if (head->next == head)
                {
                    head = NULL;
                    delete temp;
                }
                else
                {
                    Node *last = head;

                    while (last->next != head)
                        last = last->next;

                    head = head->next;
                    last->next = head;

                    delete temp;
                }
            }
            else
            {
                Node *temp = head;

                while (temp->next != head && temp->next->name != name)
                    temp = temp->next;

                if (temp->next == head)
                {
                    cout << "Student not found\n";
                }
                else
                {
                    Node *del = temp->next;
                    temp->next = del->next;
                    delete del;
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
