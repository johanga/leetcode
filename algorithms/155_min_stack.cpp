// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.
// Example:
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.

class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() 
    : s_(), minValues_()
    {
    }
    
    void push(int x) 
    {
        if ( s_.empty() )
        {
            minValues_.push(x);
        }
        else if ( x <= minValues_.top() )
        {
            minValues_.push(x);
        }
        s_.push(x);
    }
    
    void pop() 
    {
        if ( s_.top() == minValues_.top() ) minValues_.pop();
        s_.pop();
    }
    
    int top() 
    {
        return s_.top();
    }
    
    int getMin() 
    {
        return minValues_.top();
    }
    
private:
    stack<int> s_;
    stack<int> minValues_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
