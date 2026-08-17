#include <iostream>
using namespace std;

int main()
{
    int marks[] = {65, 32, 78, 45, 90, 21};
    int n = 6;

    for(int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        for(int j = i + 1; j < n; j++)
        {
            if(marks[j] < marks[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = marks[i];
        marks[i] = marks[minIndex];
        marks[minIndex] = temp;
    }

    cout << "Sorted marks using Selection Sort: ";

    for(int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    return 0;
}