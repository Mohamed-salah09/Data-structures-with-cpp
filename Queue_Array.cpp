#include <iostream>
using namespace std;
class Queue
{
    int *array;
    int front;
    int rear;
    int count;
    int size;

public:
    Queue(int s)
    {
        size = s;
        array = new int[s];
        front = 0;
        rear = -1;
        count = 0;
    }

    bool isempty()
    {
        return count == 0;
    }

    bool isfull()
    {
        return count == size-1;
    }

    void enqueue(int value)
    {
        if (isfull())
        {
            cout << "the Queue is full we can not add element\n";
            return;
        }
        rear = (rear + 1) % size;
        array[rear] = value;
        count++;
    }

    void dequeue()
    {
        if (isempty())
        {
            cout << "the Queue is already empty !\n";
        }
        front = (front + 1) % size;
        count--;
    }

    int get_front()
    {
        if (isempty())
        {
            cout << "there is no front !\n";
            return -1;
        }
        return array[front];
    }
    void display()
    {
        if (isempty())
        {
            cout << "the Queue is empty !\n";
            return;
        }
        for (int i = 0; i < count; i++)
        {
            cout << array[(front + i) % size] << " ";
        }
        cout << endl;
    }
    ~Queue()
    {
        delete[] array;
    }
};
int main()
{
    Queue q(5);

    cout << "=== Test 1: Dequeue on empty queue ===\n";
    q.dequeue(); // underflow case

    cout << "\n=== Test 2: Get front on empty queue ===\n";
    cout << q.get_front() << endl;

    cout << "\n=== Test 3: Enqueue elements ===\n";
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();

    cout << "\n=== Test 4: Enqueue on full queue ===\n";
    q.enqueue(60); // overflow case

    cout << "\n=== Test 5: Get front element ===\n";
    cout << "Front: " << q.get_front() << endl;

    cout << "\n=== Test 6: Dequeue two elements ===\n";
    q.dequeue();
    q.dequeue();
    q.display();

    cout << "\n=== Test 7: Enqueue after dequeue (circular test) ===\n";
    q.enqueue(60);
    q.enqueue(70);
    q.display();

    cout << "\n=== Test 8: Empty the queue completely ===\n";
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.display();

    cout << "\n=== Test 9: Final underflow check ===\n";
    q.dequeue();

    return 0;
}