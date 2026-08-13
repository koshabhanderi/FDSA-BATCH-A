#include<iostream>
#include<string>
using namespace std;

int main()
{

    string str;
    cout<<"Enter the paragraph: "<<endl;
    getline(cin,str);

    int length[str.length()]={0};
    int j=0;

    for(int i=0;i<str.length();i++)
    {        
        if(str[i]!=' ')
        {
           length[j]++;
        }
        else 
        {
            j++;          
        }
    }

    int max=length[0],index=0;
    for(int i=1;i<=j;i++)
    {
        if(max<length[i])
        {
            max=length[i];
            //index=i;
        }
    }

    int space=0;
    for(int i=0;i<str.length();i++)
    {
        if(length[space] == max && str[i] != ' ') 
        {
            cout<<str[i];
        }
        
        if(str[i]==' ')
        {
            if(length[space] == max) {
                cout << " "; 
            }
            space++;
        }
    }
}
