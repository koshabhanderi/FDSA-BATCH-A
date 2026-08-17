
#include<iostream>
using namespace std;
int main()
{
    int marks[5]={10,14,15,13,12};
   int last=5;
   while(last>0)
   {
    int swapped=0;
    for(int i=0;i<4;i++)
    {
        if(marks[i+1]<marks[i])
        {
            int temp=marks[i];
            marks[i]=marks[i+1];
            marks[i+1]=temp;
            swapped++;
        }
 
    }
           if(swapped==0){
            break;
        }
        else last-1;

   }
   for(int i=0;i<5;i++)
   {
       cout<<marks[i]<<endl;
   }
   return 0;

}