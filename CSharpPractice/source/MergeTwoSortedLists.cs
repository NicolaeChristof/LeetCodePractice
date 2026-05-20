// https://leetcode.com/problems/merge-two-sorted-lists

namespace LeetCodePractice.MergeTwoSortedLists
{
    // Definition for singly-linked list.
    public class ListNode
    {
        public int val;
        public ListNode next;
        public ListNode(int val = 0, ListNode next = null)
        {
            this.val = val;
            this.next = next;
        }
    }

    public class Solution
    {
        public ListNode MergeTwoLists(ListNode list1, ListNode list2)
        {
            if (list1 == null && list2 == null) return null;
            if (list1 == null) return list2;
            if (list2 == null) return list1;

            ListNode result = new ListNode(-1);
            ListNode resultIter = result;
            ListNode iter1 = list1;
            ListNode iter2 = list2;

            while (iter1 != null && iter2 != null)
            {
                if (iter1.val <= iter2.val)
                {
                    resultIter.next = iter1;
                    iter1 = iter1.next;
                }
                else
                {
                    resultIter.next = iter2;
                    iter2 = iter2.next;
                }
                resultIter = resultIter.next;
            }
            resultIter.next = iter1 == null ? iter2 : iter1;

            return result.next;
        }
    }
}