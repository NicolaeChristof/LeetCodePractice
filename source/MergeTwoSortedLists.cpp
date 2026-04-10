// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        if (list1 == nullptr && list2 == nullptr) return nullptr;
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;

        ListNode dummyNode;
        ListNode* dummyIter = &dummyNode;
        ListNode* iter1 = list1;
        ListNode* iter2 = list2;
        while (iter1 != nullptr && iter2 != nullptr)
        {
            if (iter1->val <= iter2->val)
            {
                dummyIter->next = iter1;
                iter1 = iter1->next;
            }
            else
            {
                dummyIter->next = iter2;
                iter2 = iter2->next;
            }
            dummyIter = dummyIter->next;
        }
        dummyIter->next = iter1 == nullptr ? iter2 : iter1;

        return dummyNode.next;
    }
};