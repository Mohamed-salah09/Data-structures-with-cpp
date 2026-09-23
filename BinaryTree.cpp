#include <iostream>
#include <queue>
#include <stack>
using namespace std;
class Binary_Tree
{
    struct Node // we notice that we create the struct inside the class.
    {
        Node *right;
        Node *left;
        int data;
        Node()
        {
            right = nullptr;
            left = nullptr;
            data = 0;
        }
        Node(int val)
        {
            data = val;
            right = left = nullptr;
        }
    };

public:
    Node *root;

    Binary_Tree()
    {
        root = nullptr;
    }
    Binary_Tree(int val)
    {
        Node *newnode = new Node(val);
        root = newnode;
    }
    // we will do the insert function

    // recursive
    Node *insert(Node *origin, int new_data)
    {
        if (origin == nullptr) // stopping condition
        {
            Node *newnode = new Node(new_data);
            origin = newnode;
        }
        else if (new_data < origin->data)
        {
            origin->left = insert(origin->left, new_data);
        }
        else
        {
            origin->right = insert(origin->right, new_data);
        }
        return origin;
    }

    /*
        void insert(int value)
        {
            // iterative
            if (root == nullptr)
            {
                root = new Node(value);
                return;
            }
            Node *iterator = root;
            Node *prev = nullptr;
            while (iterator != nullptr)
            {
                prev = iterator;
                if (value < iterator->data)
                {
                    iterator = iterator->left;
                }
                else if (value > iterator->data)
                {
                    iterator = iterator->right;
                }
                else
                {
                    cout << "there is duplicate value !! " << endl;
                    return;
                }
            }
            if (value < prev->data)
            {
                prev->left = new Node(value);
            }
            else if (value > prev->data)
            {
                prev->right = new Node(value);
            }
        }
            */

    // we will do the search function
    bool search(int key)
    /*
    we have 3 conditions 1- there is no tree ..2- key>node in this case go through right 3- key<node
    in this case go through  left   the success condition is that you reach the node you want .
    */
    {
        if (root == nullptr)
        {
            return false;
        }
        Node *iterator = root;
        while (iterator != nullptr)
        {
            if (key < iterator->data)
            {
                iterator = iterator->left;
            }
            else if (key > iterator->data)
            {
                iterator = iterator->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    // we have 2 ways to print or traverse through the tree
    // 1- Breadth first search   -> go level by level.
    // 2- depth first search -> go node by node .
    void BFS()
    {
        if (root == nullptr)
        {
            cout << "the tree is empty !!\n";
            return;
        }
        queue<Node *> myqueue;
        myqueue.push(root);
        while (!myqueue.empty())
        {
            Node *current = myqueue.front();
            myqueue.pop();
            cout << current->data << " ";
            if (current->left != nullptr)
            {
                myqueue.push(current->left);
            }
            if (current->right != nullptr).
            {
                myqueue.push(current->right);
            }
        }
    }

    void predorder_display(Node *current) // we will go root->left->right
    {
        if (current == nullptr)
        {
            return;
        }
        cout << current->data << " ";
        if (current->left != nullptr)
        {
            predorder_display(current->left);
        }
        if (current->right != nullptr)
        {

            predorder_display(current->right);
        }
    }

    void inorder_display(Node *current) // left ->root->right
    {
        if (current == nullptr) // stopping condition
        {
            return;
        }
        if (current->left != nullptr)
        {
            inorder_display(current->left);
        }
        cout << current->data << " ";
        if (current->right != nullptr)
        {
            inorder_display(current->right);
        }
    }

    void postorder_display(Node *current) // left->right->root
    {
        if (current == nullptr)
        {
            return;
        }
        if (current->left != nullptr)
        {
            postorder_display(current->left);
        }
        if (current->right != nullptr)
        {
            postorder_display(current->right);
        }
        cout << current->data << " ";
    }

    Node *find_min(Node *current) // the smallest node is the most left element
    {
        while (current->left != nullptr)
        {
            current = current->left;
        }
        return current;
    }

    Node *find_max(Node *current) // the biggest node is the most right element
    {
        while (current->right != nullptr)
        {
            current = current->right;
        }
        return current;
    }

    /*
    there is delete by copy and delete by merge
    */
    Node *deletenode(Node *current, int key)
    {
        // the tree is empty
        if (current == nullptr) // stopping condition
                                // the conditions is like a guidance make you reach the correct node to delete
            return nullptr;
        if (key < current->data)
        {
            current->left = deletenode(current->left, key);
        }
        else if (key > current->data)
        {
            current->right = deletenode(current->right, key);
        }
        else
        {
            // now i will delete
            //  case 1: no children
            if (current->left == nullptr && current->right == nullptr)
            {
                delete current;
                return nullptr;
            }
            // case 2: one child
            // but i do not know whether the child is on the right or on the left.
            else if (current->left == nullptr)
            {
                Node *temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr)
            {
                Node *temp = current->left;
                delete current;
                return temp;
            }

            else
            {
                // case 3: 2 children
                Node *successor = find_min(current->right); // we have 2 options 1- we replace it with the most minimum in the right
                // or we replace it with the most biggest  on the right
                current->data = successor->data;
                current->right = deletenode(current->right, successor->data);
            }
        }
        return current;
    }
};

int main()
{
    Binary_Tree list(10);

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.insert(5);
    list.insert(6);
    list.insert(7);
    list.insert(8);
    list.insert(9);

    list.root = list.deletenode(list.root, 5);

    list.postorder_display(list.root);

    return 0;
}