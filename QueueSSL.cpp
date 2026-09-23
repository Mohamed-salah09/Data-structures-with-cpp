#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

public:
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

class queue
{
    Node *head;
    Node *tail;
    int length;

public:
    queue()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }
    queue(int value)
    {
        Node *newnode = new Node(value);
        head = tail = newnode;
        length = 1;
    }

    bool isempty()
    {
        return head == nullptr;
    }

    void enqueue(int value)
    {
        Node *newnode = new Node(value);
        if (isempty())
        {
            tail = head = newnode;
        }
        tail->next = newnode;
        tail = newnode;
    }

    int dequeue()
    {
        int hold = 0;
        if (isempty())
        {
            cout << "the queue is empty!!\n";
        }
        else if (head == tail)
        {
            delete head;
            head = tail = nullptr;
        }
        else
        {
            Node *delptr = head;
            hold = head->data;
            head = head->next;
            delete delptr;
        }
        length--;
        return hold;
    }
    void display() // the same code as linkedlist
    {
        Node *iterator = head;
        while (iterator != nullptr)
        {
            cout << iterator->data << endl;
            iterator = iterator->next;
        }
        cout << endl;
    }
    int peek_front()
    {
        return head->data;
    }
    int peek_Rear()
    {
        return tail->data;
    }

    void clear()
    {
        while (!isempty())
        {
            dequeue();
        }
    }
    ~queue()
    {
        clear();
    }
};

int main()
{
    queue q;

    cout << "=== Test 1: isempty on empty queue ===\n";
    cout << (q.isempty() ? "Queue is empty\n" : "Queue not empty\n");

    cout << "\n=== Test 2: enqueue elements ===\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue after enqueue:\n";
    q.display();

    cout << "\n=== Test 3: peek front ===\n";
    cout << "Front element: " << q.peek_front() << endl;

    cout << "\n=== Test 4: peek rear ===\n";
    cout << "Rear element: " << q.peek_Rear() << endl;

    cout << "\n=== Test 5: dequeue one element ===\n";
    cout << "Removed: " << q.dequeue() << endl;

    cout << "Queue after dequeue:\n";
    q.display();

    cout << "\n=== Test 6: multiple dequeues ===\n";
    cout << "Removed: " << q.dequeue() << endl;
    cout << "Removed: " << q.dequeue() << endl;

    cout << "Queue after multiple dequeues:\n";
    q.display();

    cout << "\n=== Test 7: check state ===\n";
    cout << "Front: " << q.peek_front() << endl;
    cout << "Rear: " << q.peek_Rear() << endl;

    cout << "\n=== Test 8: clear queue ===\n";
    q.clear();

    cout << (q.isempty() ? "Queue is empty after clear\n" : "Not empty") << endl;

    cout << "\n=== Test 9: dequeue from empty queue ===\n";
    cout << "Removed: " << q.dequeue() << endl;

    cout << "\n=== End of tests (destructor will run automatically) ===\n";

    return 0;
}