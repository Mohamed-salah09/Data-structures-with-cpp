#include <iostream>
#include <vector>
using namespace std;
template <typename t>
class Stack
{
    vector<t> Stack;

public:
    void push(t value)
    {
        Stack.push_back(value);
    }

    bool isempty()
    {
        return Stack.empty();
    }

    void pop()
    {
        if (isempty())
        {
            cout << "the stack is empty !\n";
        }
        Stack.pop_back();
    }

    int get_size()
    {
        return Stack.size();
    }

    t peek()
    {
        return Stack[get_size() - 1];
    }

    void display()
    {
        if (isempty())
        {
            cout << "the stack is empty !\n";
        }
        for (int i = Stack.size() - 1; i >= 0; i--)
        {
            cout << Stack[i] << endl;
        }
        cout << endl;
    }
    void clear()
    {
        Stack.clear();
    }

    bool contains(int key)
    {
        for (int value : Stack)
        {
            if (value == key)
            {
                return true;
                break;
            }
        }
        return false;
    }
};
bool ispair(char first, char last)
{
    if (first == '(' && last == ')')
        return true;
    else if (first == '{' && last == '}')
        return true;
    else if (first == '[' && last == ']')
        return true;
    else
    {
        return false;
    }
}

/*bool check_isParenthesis_balanced(string expression)

{
   Stack<char> S;
   bool isbalanced = true;
   for (int i = 0; i < expression.length(); i++)
   {
       char nextchar = expression[i];
       switch (nextchar)
       {
       case '(':
       case '{':
       case '[':
           S.push(nextchar); // when you see opening just push it to stack
           break;
       case ')':
       case '}':
       case ']':
           if (S.isempty()) // we here apply first rule
           {
               isbalanced = false;
               break;
           }
           else
           {
               char topchar = S.peek(); // we will remove the nextchar and then check it outside
               S.pop();
               if (!ispair(topchar, nextchar)) // check here
               {
                   isbalanced = false;
                   break;
               }
           }
           break;
       default:
           break;
       }
       if (!isbalanced)
       {
           break;
       }
   }
   if (!S.isempty())
   {
       isbalanced = false;
   }
   return isbalanced;
}*/
bool check_isParenthesis_balanced(string expression)
{
    Stack<char> S;
    bool isbalanced = true;
    for (int i = 0; i < expression.length(); i++)
    {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{')
        {
            S.push(expression[i]);
        }
        else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}')
        {
            if (S.isempty() || !ispair(S.peek(), expression[i]))
            {
                isbalanced = false;
                break;
            }
            else
            {
                S.pop();
            }
        }
    }
    return S.isempty();
}
int main()
{
    string ex;
    cout << "Enter your expression : " << endl;
    cin >> ex;
    if (check_isParenthesis_balanced(ex))
    {
        cout << "the Expression is true, smile !!" << endl;
    }
    else
    {
        cout << " the Expression is false !!" << endl;
    }

    return 0;
}