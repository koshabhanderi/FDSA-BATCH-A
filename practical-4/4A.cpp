#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head=NULL;
    int choice, value, pos;

    while(true)
    {
        cout << "\n1. Insert Front";
        cout << "\n2. Insert End";
        cout << "\n3. Insert Position";
        cout << "\n4. Display";
        cout << "\n5. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        if(choice == 1)
        {
            cout << "Enter value: ";
            cin >> value;

            Node *newNode=new Node();
            newNode->data=value;
            newNode->next=head;
            head=newNode;
        }

        else if(choice == 2)
        {
            cout << "Enter value: ";
            cin >> value;

            Node *newNode=new Node();
            newNode->data=value;
            newNode->next=NULL;

            if(head == NULL)
            {
                head=newNode;
            }
            else
            {
                Node *temp=head;

                while(temp->next != NULL)
                {
                    temp=temp->next;
                }

                temp->next=newNode;
            }
        }

        else if(choice == 3)
        {
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            if(pos <= 0)
            {
                cout << "Invalid position";
            }
            else if(pos == 1)
            {
                Node *newNode=new Node();
                newNode->data=value;
                newNode->next=head;
                head=newNode;
            }
            else
            {
                Node *temp=head;

                for(int i=1; i < pos - 1 && temp != NULL; i++)
                {
                    temp=temp->next;
                }

                if(temp == NULL)
                {
                    cout << "Position does not exist";
                }
                else
                {
                    Node *newNode=new Node();
                    newNode->data=value;
                    newNode->next=temp->next;
                    temp->next=newNode;
                }
            }
        }

        else if(choice == 4)
        {
            Node *temp=head;

            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp=temp->next;
            }
        }

        else if(choice == 5)
        {
            break;
        }
    }

    return 0;
}
