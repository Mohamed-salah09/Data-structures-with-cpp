#include <iostream>
using namespace std;

// ========== Node Definition ==========
struct Node
{
    int value;
    Node *next;

    Node()
    {
        value = 0;
        next = nullptr;
    }

    Node(int value)
    {
        this->value = value;
        next = nullptr;
    }
};
// =====================================

class CircularLinkedList
{
public:
    Node *head;
    int length;

    CircularLinkedList()
    {
        head = nullptr;
        length = 0;
    }

    CircularLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        head->next = head; // Points to itself, circular
        length = 1;
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display." << endl;
        }
        else
        {
            Node *temp = head;
            do
            {
                cout << temp->value << " ";
                temp = temp->next;
            } while (temp != head); // Loop until we come back to the head
            cout << endl;
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            head->next = head; // Points to itself, circular
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Circular connection
        }
        length++;
    }

    void preAppend(int value)
    {
        Node *newNode = new Node(value);
        if (isEmpty())
        {
            head = newNode;
            head->next = head; // Points to itself, circular
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Circular connection
            head = newNode;       // Update head to the new node
        }
        length++;
    }

    void deleteLast()
    {
        if (isEmpty())
        {
            cout << "Nothing to delete!" << endl;
            return;
        }
        if (length == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *prev = head;
            while (prev->next != temp)
            {
                prev = prev->next;
            }
            prev->next = head; // Connect the second-last node to head
            delete temp;
        }
        length--;
    }

    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Nothing to delete!" << endl;
            return;
        }
        if (length == 1)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            Node *last = head;
            while (last->next != head)
            {
                last = last->next;
            }
            head = head->next;
            last->next = head; // Update last node's next pointer to new head
            delete temp;
        }
        length--;
    }

    Node *get(int index)
    {
        if (index < 0 || index >= length)
            return nullptr;
        Node *temp = head;
        for (int i = 0; i < index; ++i)
        {
            temp = temp->next;
        }
        return temp;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;

        if (index == 0)
        {
            preAppend(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }

        Node *newNode = new Node(value);
        Node *prevNode = get(index - 1);
        Node *nextNode = prevNode->next;

        prevNode->next = newNode;
        newNode->next = nextNode;

        length++;
        return true;
    }

    void deleteNode(int index)
    {
        if (isEmpty())
        {
            cout << "No Nodes to delete!" << endl;
            return;
        }
        if (index < 0 || index >= length)
            return;
        if (index == 0)
        {
            deleteFront();
            return;
        }
        if (index == length - 1)
        {
            deleteLast();
            return;
        }

        Node *prevNode = get(index - 1);
        Node *delptr = prevNode->next;
        Node *nextNode = delptr->next;

        prevNode->next = nextNode;
        delete delptr;
        length--;
    }

    void reverseList()
    {
        if (isEmpty())
            return;

        Node *prev = nullptr;
        Node *current = head;
        Node *next = nullptr;

        do
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        } while (current != head);

        head->next = prev;
        head = prev; // Update head to the last node
    }

    void clear()
    {
        while (!isEmpty())
        {
            deleteFront();
        }
    }

    void recursiveDisplay(Node *P)
    {
        if (P != nullptr)
        {
            cout << P->value << " ";
            recursiveDisplay(P->next);
            if (P->next == head)
                return; // Stop if we've looped back to head
        }
    }

    void create(int A[], int size)
    {
        for (int i = 0; i < size; i++)
        {
            append(A[i]);
        }
    }

    void Search(int index)
    {
        Node *result = get(index);
        if (result)
        {
            cout << result->value << endl;
        }
        else
        {
            cout << "Invalid index" << endl;
        }
    }

    void addInOrder(int value)
    {
        if (isEmpty() || value < head->value)
        {
            preAppend(value);
        }
        else
        {
            Node *temp = head;
            while (temp->next != head && temp->next->value < value)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(value);
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
        }
    }

    ~CircularLinkedList()
    {
        Node *temp = head;
        while (head != nullptr)
        {
            Node *delptr = head;
            head = head->next;
            delete delptr;
            if (head == temp)
                break; // End of circular list
        }
    }
};
