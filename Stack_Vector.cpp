#include <iostream>
#include <vector>
using namespace std;
class Stack
{
    vector<int> Stack;

public:
    void push(int value)
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

    int peek()
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
int main()
{
    Stack List;
    List.push(10);
    List.push(20);
    List.push(30);
    cout << "display test case before deleting any element :: \n";
    List.display();
    cout << "=============================================================== \n";
    cout << "After the pop ::\n";
    List.pop();
    List.display();
    cout << "================================================================= \n";
    cout << "the peak function  test case :: \n";
    cout << "the first elements is " << List.peek() << endl;
    cout << "================================================================== \n";
    cout << "the height test case :: \n";
    cout << "the hight is : " << List.get_size() << endl;
    cout << "===================================================================== \n";
    cout << "the contain function test case:: \n";
    if (List.contains(4))
    {
        cout << "FOUND!!\n";
    }
    else
    {
        cout << "NOT FOUND!!\n";
    }
    cout << "======================================================================== \n";
    cout << "the clear function test case :: \n";
    List.clear();
    if (List.isempty())
    {
        cout << "the function works correctly ,, smile !!\n";
    }
    return 0;
}