// 225. Implement Stack using Queues

// Implement the following operations of a stack using queues.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// empty() -- Return whether the stack is empty.
// Notes:
// You must use only standard operations of a queue -- which means only push to 
// back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, queue may not be supported natively. You may simulate 
// a queue by using a list or deque (double-ended queue), as long as you use only 
// standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top 
// operations will be called on an empty stack).

#include "leetcode.hpp"

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty())
        {
            q1.push(x);
            while(!q2.empty())
            {
                q1.push(q2.front());
                q2.pop();
            }
        }
        else
        {
            q2.push(x);
            while(!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = 0;
        if(q1.empty())
        {
            val = q2.front();
            q2.pop();
        }
        else
        {
            val = q1.front();
            q1.pop();
        }
        return val;
    }
    
    /** Get the top element. */
    int top() {
        int val = 0;
        if(q1.empty())
            val = q2.front();
        else
            val = q1.front();
        return val;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1, q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */


int main(int argc, char const *argv[])
{
    MyStack sln;
    CHECK_TRUE(sln.empty());
    sln.push(1);
    CHECK_FALSE(sln.empty());
    CHECK_TRUE(sln.top() == 1);
    CHECK_TRUE(sln.pop() == 1);
    CHECK_TRUE(sln.empty());

    sln.push(2);
    sln.push(3);
    sln.push(4);
    CHECK_TRUE(sln.top() == 4);
    CHECK_TRUE(sln.pop() == 4);

    sln.push(5);
    CHECK_TRUE(sln.top() == 5);
    CHECK_TRUE(sln.pop() == 5);
    CHECK_TRUE(sln.pop() == 3);
    CHECK_TRUE(sln.pop() == 2);
    CHECK_TRUE(sln.empty());

    TEST_REPORT();
}