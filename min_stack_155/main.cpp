#include <iostream>
#include <string> 
#include <vector>

using namespace std;


//不同步栈，这里辅助栈和数据栈的长度不一致，这样在push和pop操作时，需要判断是否对辅助栈进行相应的操作
//同步栈，同步栈其实就是使得辅助栈和数据栈的长度一致，这样在pop操作时，辅助栈也进行pop操作，但是在push操作时，往辅助栈中push的元素值需要进行考虑
class MinStack 
{
public:
    /** initialize your data structure here. */
    MinStack() 
    { }
    
    void push(int x) 
    {
        _stack.push_back(x);
        if (_min_stack.size() == 0)
            _min_stack.push_back(x);
        else if (x <= _min_stack.back())
            _min_stack.push_back(x);
    }
    
    void pop() 
    {
        if (empty())
            return;
        if (_stack.back() == _min_stack.back())
            _min_stack.pop_back();
        _stack.pop_back();
    }
    
    int top() 
    {
        return _stack.back();
    }
    
    int getMin() 
    {
        return _min_stack.back();
    }
private:
    bool empty(void)
    {
        return _stack.size() == 0;
    }

    // bool full(void)
    // {
    //     return !empty();
    // }

private: 
    vector<int> _min_stack;
    vector<int> _stack;
};

// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

int main(void)
{
    MinStack min_stack;
    min_stack.push(-2);
    //cout << "-==------------------\n";
    min_stack.push(0);
    min_stack.push(-3);
    //cout << "-==------------------\n";
    cout << min_stack.getMin() << endl;
    min_stack.pop();
    cout << min_stack.top() << endl;
    cout << min_stack.getMin() << endl;




    return 0;
}