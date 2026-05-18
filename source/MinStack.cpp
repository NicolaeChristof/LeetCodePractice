// https://leetcode.com/problems/min-stack
#include <stack>

// Two stack approach
class MinStack
{
    std::stack<int> mainStack;
    std::stack<int> minStack;
public:
    MinStack()
    {

    }

    void push(int val)
    {
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.emplace(val);
        }
        mainStack.emplace(val);
    }

    void pop()
    {
        if (mainStack.top() == minStack.top())
        {
            minStack.pop();
        }
        mainStack.pop();
    }

    int top() const
    {
        return mainStack.top();
    }

    int getMin() const
    {
        return minStack.top();
    }
};

// Stack of pairs approach
//class MinStack
//{
//    std::stack<std::pair<int, int>> stack;
//    int currentMin = INT_MAX;
//public:
//    MinStack()
//    {
//
//    }
//
//    void push(int val)
//    {
//        if (stack.empty() || val <= currentMin)
//        {
//            stack.emplace(val, val);
//            currentMin = val;
//        }
//        else
//        {
//            stack.emplace(val, currentMin);
//        }
//    }
//
//    void pop()
//    {
//        stack.pop();
//        currentMin = stack.empty() ? INT_MAX : stack.top().second;
//    }
//
//    int top() const
//    {
//        return stack.top().first;
//    }
//
//    int getMin() const
//    {
//        return stack.top().second;
//    }
//};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */