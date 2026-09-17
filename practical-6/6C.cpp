#include <iostream>
using namespace std;

int priority(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;

    if (ch == '*' || ch == '/')
        return 2;

    return 0;
}

int main()
{
    string infix;
    char stack[100];
    int top = -1;

    cin >> infix;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            cout << ch;
        }

        else if (ch == '(')
        {
            top++;
            stack[top] = ch;
        }

        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                cout << stack[top];
                top--;
            }

            top--;
        }

        else
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
            {
                cout << stack[top];
                top--;
            }

            top++;
            stack[top] = ch;
        }
    }

    while (top != -1)
    {
        cout << stack[top];
        top--;
    }

    return 0;
}
