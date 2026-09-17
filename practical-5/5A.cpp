#include <iostream>
using namespace std;

struct Node
{
    string song;
    Node *prev;
    Node *next;
};

int main()
{
    Node *head = NULL;
    int choice;
    string song, after;

    while (true)
    {
        cout << "\n1. Add Beginning";
        cout << "\n2. Add End";
        cout << "\n3. Insert After";
        cout << "\n4. Remove First";
        cout << "\n5. Count";
        cout << "\n6. Display";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cin >> song;

            Node *newNode = new Node;
            newNode->song = song;
            newNode->prev = NULL;
            newNode->next = head;

            if (head != NULL)
                head->prev = newNode;

            head = newNode;
        }

        else if (choice == 2)
        {
            cin >> song;

            Node *newNode = new Node;
            newNode->song = song;
            newNode->next = NULL;

            if (head == NULL)
            {
                newNode->prev = NULL;
                head = newNode;
            }
            else
            {
                Node *temp = head;

                while (temp->next != NULL)
                    temp = temp->next;

                temp->next = newNode;
                newNode->prev = temp;
            }
        }

        else if (choice == 3)
        {
            cin >> after;
            cin >> song;

            Node *temp = head;

            while (temp != NULL && temp->song != after)
                temp = temp->next;

            if (temp == NULL)
            {
                cout << "Song not found\n";
            }
            else
            {
                Node *newNode = new Node;
                newNode->song = song;

                newNode->next = temp->next;
                newNode->prev = temp;

                if (temp->next != NULL)
                    temp->next->prev = newNode;

                temp->next = newNode;
            }
        }

        else if (choice == 4)
        {
            if (head == NULL)
            {
                cout << "Playlist is empty\n";
            }
            else
            {
                Node *temp = head;
                head = head->next;

                if (head != NULL)
                    head->prev = NULL;

                delete temp;
            }
        }

        else if (choice == 5)
        {
            int count = 0;
            Node *temp = head;

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            cout << "Songs = " << count << endl;
        }

        else if (choice == 6)
        {
            Node *temp = head;

            while (temp != NULL)
            {
                cout << temp->song << " ";
                temp = temp->next;
            }

            cout << endl;
        }

        else if (choice == 7)
        {
            break;
        }
    }

    return 0;
}
