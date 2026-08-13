#include<iostream>
using namespace std;
int main()
{
    
    int n;
    cout<< "Enter the number of item: ";
    cin>>n;
    string arr[n];

    int h;
    cout<<"Enter the number of hours: ";
    cin>>h;
    int x=h;

    cout<<"enter each item: ";

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    string first;
    while(h!=0)
    {
        first=arr[0];
        for(int i=0;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        arr[n-1]=first;
        
        cout<<"After hour no. "<< x-h+1<<": "<<endl;
        cout<<"[";

        for(int i=0;i<n;i++)
        {
           if(i!=(n-1))
           {
            cout<<arr[i]<<",";
           }
           else cout<<arr[i];
        }
        cout<<"]\n";
        h--;
    }
}
