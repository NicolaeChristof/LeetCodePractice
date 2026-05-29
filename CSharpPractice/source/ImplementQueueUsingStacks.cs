// https://leetcode.com/problems/implement-queue-using-stacks
using System.Collections.Generic;

namespace LeetCodePractice.ImplementQueueUsingStacks
{
    public class MyQueue
    {
        Stack<int> m_forwardStack = new Stack<int>();
        Stack<int> m_reverseStack = new Stack<int>();
        int m_frontElement = -1;

        public MyQueue()
        {
            
        }

        public void Push(int x)
        {
            if (m_forwardStack.Count == 0) m_frontElement = x;
            m_forwardStack.Push(x);
        }

        public int Pop()
        {
            while (m_forwardStack.Count > 0)
            {
                m_reverseStack.Push(m_forwardStack.Pop());
            }

            int result = m_reverseStack.Pop();
            if (m_reverseStack.Count > 0) m_frontElement = m_reverseStack.Peek();

            while (m_reverseStack.Count > 0)
            {
                m_forwardStack.Push(m_reverseStack.Pop());
            }

            return result;
        }

        public int Peek()
        {
            return m_frontElement;
        }

        public bool Empty()
        {
            return m_forwardStack.Count == 0;
        }
    }

    /**
     * Your MyQueue object will be instantiated and called as such:
     * MyQueue obj = new MyQueue();
     * obj.Push(x);
     * int param_2 = obj.Pop();
     * int param_3 = obj.Peek();
     * bool param_4 = obj.Empty();
     */
}