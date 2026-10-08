#include <iostream>
using namespace std;

class queue{
    int *arr;
    int n;
    int front;
    int rear;

public:
    queue(int size){
        n=size;
        arr=new int[n];
        front=-1;
        rear=-1;
    }

    void join(int token){
        if(rear == n - 1){
            cout<<"error"<<endl;
            return;
        }

        if(front == -1)
            front=0;

        rear++;
        arr[rear]=token;
    }

    void serve(){
        if(front == -1 || front>rear){
            cout<<"error"<<endl;
            return;
        }
        front++;

        if(front>rear){
            front=-1;
            rear=-1;
        }
    }

    void displayFront(){
        if(front == -1)
            cout<<"Empty"<<endl;
        else
            cout<<arr[front]<<endl;
    }
};

int main(){
    int n, operations;
    cin >> n;
    cin >> operations;

    queue q(n);

    for(int i=0; i < operations; i++){
        string operation;
        cin >> operation;

        if(operation == "join"){
            int token;
            cin >> token;
            q.join(token);
        }
        else if(operation == "serve"){
            q.serve();
        }

        q.displayFront();
    }

    return 0;
}
