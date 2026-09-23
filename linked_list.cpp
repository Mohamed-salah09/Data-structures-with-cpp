#include <iostream>
using namespace std;
struct node
{
    // what i understand that the linked list is a kind of  data structures that stores data in nodes
    /*
    unlike arrays , the data does not  stored in stack in  adjacent places
    */
public:
    int value;
    node *next;

    node() // default constructor
    {
        value = 0;
        next = nullptr;
    }
    node(int v) // paramaterised
    {
        this->value = v;

        next = nullptr;
    }
};

class my_linkedlist
{
public:
    node *head;
    node *tail;
    int length;
    my_linkedlist()
    {
        head = nullptr;
        tail = nullptr;
        length = 0;
    }

    my_linkedlist(int value)
    {
        node *newnode = new node(value);
        head = newnode;
        tail = newnode;
        length = 1;
    }

    ~my_linkedlist()
    /*
    the logic is simple all we do the we  1- make temp and make it refer to head.
    then 2- we move the head to the next node  then 3- we remove temp that refer to the previous
    then 4- we make the head = the head and do what we did again .

    easy ya man

    */
    {
        node *temp = head;
        while (head != nullptr)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    /*
    the logic is simple  when the linked list be empty  and the answer is when the head is nullptr
    meaning that when the head is empty so , the linked list is empty.

    peace ya man

    */
    bool is_empty()
    {
        return head == nullptr;
    }

    void display()
    {
        if (is_empty())
        {
            cout << "the linked_list is empty  we can not display anything !!\n";
        }
        else
        {
            node *temp = head;
            while (head != nullptr)
            {
                cout << temp->value;
                temp = temp->next;
            }
        }
    }
    void append(int value)
    {
        node *newnode = new node(value);
        /*
        i have 2 conditions 1- the LINKED list is empty  or the  not

        focus
        (2)->(5)->(7)
        or
        nothing
         all the logic we do is
         if[nothing ]: (newnode) is the head and the tail
         if[the first case ]
         (2)->(5)->(7)->(4) we tell the thing after the tail to be equal the new node we create then we make the tail new node

        */
        if (is_empty())
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        length++;
    }

    void delete_last()
    {
        // we have 3 cases 1- the ll is empty 2- there is 1 element 3- there are multiple elements
        if (is_empty()) // case 1
        {
            cout << "the linked list is empty !!\n";
            return; // tell the compiler to exit ;
        }

        if (length == 1) // case 2;
        {
            head = nullptr;
            tail = nullptr;
            // we depend on default destructor from node to delete my nodes ;
        }
        // case 3
        node *delptr = head;
        node *prevptr = nullptr;
        while (delptr->next != nullptr)
        {
            prevptr = head;
            delptr = delptr->next;
        }
        prevptr->next = nullptr;
        delete delptr;
        tail = prevptr;
        length--;
    }
    void pre_append(int value)
    {
        // we first create  node
        node *newnode = new node(value);
        // we have 2 cases
        if (is_empty())
        {
            head = newnode;
            tail = newnode;
        }
        // how to tell the compiler that we are in the first node?
        // the answer is that we assign the next of our node to head

        else
        {
            newnode->next = head;
            head = newnode;
        }
        length++;
    }

    void delete_front()
    { // we have 3 cases
        if (is_empty())
        {
            cout << "already empty !!\n";
        }

        node *delptr = head;
        if (length == 1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head = head->next;
        }
        delete delptr;
        length--;
    }

    node *get(int index) // we need to get  a node
    {
        // as usual we have 2 cases

        node *temp = head;
        if (index < 0 || index >= length) // first case is that the index is out of  boundary
        {
            return nullptr;
        }
        else
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next; // its like i++
            }
            return temp;
        }
    }

    bool set(int index, int value)
    {
        node *temp = get(index);
        if (temp != nullptr)
        {
            temp->value = value;
            return true;
        }
        else
        {
            return false;
        }
    }

    // we need to make the insert function
    bool insert(int index, int value)
    {
        // we first need to check if we are in the range of nodes or not
        if (index < 0 || index > length)
        {
            return false;
        }
        else if (index == 0) // we need to check if the user will input from begining or end
        {
            pre_append(value);
            return true;
        }
        else if (index == length)
        {
            append(value);
            return true;
        }
        else
        {
            node *newnode = new node(value);
            node *temp = get(index - 1);

            newnode->next = temp->next; //-> // which is the place i want to put the value in
            temp->next = newnode;
            length++;
            return true;

        } //  الخلاصة كل اللي بيحصل  ان انا بحط  اللي بعد النود اللي عاملها هي المكان اللي عايز
        // احط فيه و بخلي اللي بعد العنصر اللي قبل  المكان اللي عايز احط فيه هو النود اللي عاملها
        // من الاخر  انا بحطه ف النص  بينهم
    }

    void delete_node(int index)
    {
        // as usual we have 4 cases
        if (is_empty())
        {
            cout << "the linked list is empty !!\n";
            return;
        }
        if (index < 0 || index >= length) // out of range
        {
            return;
        }
        if (index == 0)
        {
            return delete_front();
        }
        if (index == length - 1)
        {
            return delete_last();
        }

        node *prevptr = get(index - 1); // all we do that we link betweeen the prev and next of our node
        // then we will delete
        node *delptr = prevptr->next;
        prevptr->next = delptr->next;
        delete delptr;
        length--;
    }

    void reverse()
    {
        node *temp = head;
        head = tail;
        tail = temp;
        node *after = temp->next;
        node *before = nullptr;
        for (int i = 0; i < length; i++) // all we do is  playing  with direction
        {
            after = temp->next;
            temp->next = before;

            before = temp;
            temp = after;
        }
    }
};

int main()
{
    my_linkedlist list;
    list.append(1);
    list.append(4);
    list.append(7);
    list.display();

    return 0;
}