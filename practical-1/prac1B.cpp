#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of books borrowed";
    cin>>n;

    cout<<"Enter the ID of each book:\n";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cout<<"Book "<<i+1<<": ";
        cin>>arr[i];

    }

    cout<<"Books ID that needed to be restored:\n";
    int count;
    for(int i=0;i<n;i++)
    {
        count=1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                count++;
                arr[j]=-1;
            }
        }
        if(count>1 && arr[i]!=-1)
        {
            cout<<arr[i]<<endl;
        }
    }



}
