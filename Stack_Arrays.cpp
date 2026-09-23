#include <iostream>
using namespace std;
class Stack
{
private:
    int *array;
    int size;
    int top;

public:
    Stack(int s)
    {
        size = s;
        array = new int[s];
        top = -1;
    }

    bool isempty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top == size - 1;
    }
    void push(int value)
    {
        // we must check isfull not isempty  .. why?
        // because the edge case is when the array is full(overflow).
        if (isfull())
        {
            cout << "we can not add element because the array is full !!\n";
            return;
        }
        array[++top] = value;
    }
    void pop(int &num)
    {
        // here we must check empty ?
        // because if the array is empty and i do pop the top will become -1 and it is not true ( overflow will occur).
        if (isempty())
        {
            cout << "there is nothing to delete\n";
            return;
        }
        else
        {
            num = array[top];
            top--;
        }
    }

    int peek()
    {
        if (isempty())
        {
            cout << "the Stack is empty !!\n";
            return -1;
        }
        return array[top];
    }

    void display()
    {
        if (isempty())
        {
            cout << "the Stack is empty !!\n";
            return;
        }
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << endl;
        }
    }
    ~Stack()
    {
        delete[] array;
    }

    bool contains(int key)
    {
        for (int i = 0; i <= top; i++)
        {
            if (array[i] == key)
            {
                return true;
            }
        }
        return false;
    }
    int get_size()
    {
        return top + 1;
    }
};
int main()
{
    Stack List(6);
    List.push(10);
    List.push(20);
    List.push(30);
    cout << "display test case before deleting any element :: \n";
    List.display();
    cout << "=============================================================== \n";
    cout << "After the pop ::\n";
    int x;
    cout << "enter a value to pop :: \n";
    cin >> x;
    List.pop(x);
    List.display();
    cout << "================================================================= \n";
    cout << "the peak function  test case :: \n";
    cout << "the first elements is " << List.peek() << endl;
    cout << "================================================================== \n";
    cout << "the height test case :: \n";
    cout << "the hight is : " << List.get_size() << endl;
    cout << "===================================================================== \n";
    cout << "the contain function test case:: \n";
    if (List.contains(20))
    {
        cout << "FOUND!!\n";
    }
    else
    {
        cout << "NOT FOUND!!\n";
    }

    return 0;
}