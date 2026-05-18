// https://leetcode.com/problems/implement-queue-using-stacks
#include <stack>

class MyQueue
{
    std::stack<int> m_forwardStack;
    std::stack<int> m_reverseStack;
    int m_frontElement;
public:
    MyQueue() : m_forwardStack(), m_reverseStack(), m_frontElement(-1)
    {

    }

    void push(int x)
    {
        if (m_forwardStack.empty()) m_frontElement = x;
        m_forwardStack.push(x);
    }

    int pop()
    {
        while (!m_forwardStack.empty())
        {
            m_reverseStack.push(m_forwardStack.top());
            m_forwardStack.pop();
        }

        int result = m_reverseStack.top();
        m_reverseStack.pop();
        if (!m_reverseStack.empty()) m_frontElement = m_reverseStack.top();

        while (!m_reverseStack.empty())
        {
            m_forwardStack.push(m_reverseStack.top());
            m_reverseStack.pop();
        }

        return result;
    }

    int peek()
    {
        return m_frontElement;
    }

    bool empty()
    {
        return m_forwardStack.empty();
    }
};