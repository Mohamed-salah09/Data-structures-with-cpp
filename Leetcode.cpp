
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        // we first need to know the tail
        ListNode *tail = head;
        while (tail->next != nullptr)
        {
            tail = tail->next;
        }

        for (int i = 1; i <= k; i++)
        {
            tail->next = head;
            head = tail;
            tail->next = 0;
        }
    }
};