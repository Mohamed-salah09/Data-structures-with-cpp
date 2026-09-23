#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *next;

    Node()
    {
        data = 0;
        next = nullptr;
    }

    Node(int v)
    {
        data = v;
        next = nullptr;
    }
};
class Stack
{

    Node *top;
    int height;

public:
    Stack()
    {
        top = nullptr;
        height = 0;
    }
    Stack(int v)
    {
        Node *newnode = new Node(v);
        top = newnode;
        height = 1;
    }
    bool isempty()
    {
        return top == nullptr;
    }

    void push(int value) // the same code of linkedlist.
    {
        Node *newnode = new Node(value);
        newnode->next = top;
        top = newnode;
        height++;
    }

    void pop()
    {
        // first we should handle edge cases , we have 2 caes
        if (isempty())
        {

            cout << "the stack is already empty !!\n";
            return;
        }

        Node *delptr = top;
        top = top->next;
        delete delptr;
        height--;
    }

    void display() // the same code as linkedlist
    {
        Node *iterator = top;
        while (iterator != nullptr)
        {
            cout << iterator->data << endl;
            iterator = iterator->next;
        }
        cout << endl;
    }

    int get_height()
    {
        return height;
    }

    int peek()
    {
        if (isempty())
        {
            cout << "stack is empty\n";
            return -1;
        }
        return top->data;
    }

    bool contains(int key)
    {
        // this function made to apply the linear search
        Node *iterator = top;
        while (iterator != nullptr)
        {
            if (iterator->data == key)
            {
                return true;
            }
            iterator = iterator->next;
        }
        return false;
    }
    void clear()
    {
        // this function made to remove all the stack
        while (!isempty())
        {
            pop();
        }
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
    cout << "the hight is : " << List.get_height() << endl;
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