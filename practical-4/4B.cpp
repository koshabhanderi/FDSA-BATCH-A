#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void display(Node *head)
{
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void reversePrint(Node *head)
{
    if (head == NULL)
        return;

    reversePrint(head->next);
    cout << head->data << " ";
}

int main()
{
    Node *head = NULL;
    int n, value, deleteValue;

    cout << "Enter number of patients: ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> value;

        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    cout << "Queue: ";
    display(head);

    cout << "Enter value to delete: ";
    cin >> deleteValue;

    if (head != NULL && head->data == deleteValue)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    else
    {
        Node *temp = head;

        while (temp != NULL && temp->next != NULL)
        {
            if (temp->next->data == deleteValue)
            {
                Node *del = temp->next;
                temp->next = del->next;
                delete del;
                break;
            }

            temp = temp->next;
        }
    }

    cout << "After deletion: ";
    display(head);

    cout << "Forward: ";
    display(head);

    cout << "Reverse: ";
    reversePrint(head);

    return 0;
}
