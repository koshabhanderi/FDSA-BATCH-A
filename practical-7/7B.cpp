#include <iostream>
using namespace std;

struct node{
    string patient;
    node *next;
};

class Queue{
    node *front;
    node *rear;

public:
    Queue(){
        front=NULL;
        rear=NULL;
    }

    void arrive(string patient){
        node *newnode=new node;
        newnode->patient=patient;
        newnode->next=NULL;

        if(rear==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
    }

    void attend(){
        if(front==NULL){
            cout << "Error" << endl;
            return;
        }

        node *temp=front;
        front=front->next;

        if(front==NULL)
            rear=NULL;

        delete temp;
    }

    void displayFront(){
        if(front==NULL)
            cout << "Empty" << endl;
        else
            cout << front->patient << endl;
    }
};

int main(){
    int operations;
    cin>>operations;

    Queue q;

    for(int i=0; i < operations; i++){
        string operation;
        cin>>operation;

        if(operation=="arrive"){
            string patient;
            cin>>patient;
            q.arrive(patient);
        }
        else if(operation=="attend"){
            q.attend();
        }

        q.displayFront();
    }

    return 0;
}
