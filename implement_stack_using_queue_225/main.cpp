#include <iostream>
#include <vector>
#include <queue>

using namespace std;

//可以使用两个队列来实现，压入O(1), 弹出O(N)
//可以使用两个队列来实现，压入O(N), 弹出O(1)，思想就是将一个队列安排到另一个队列当中，另一个队列中的头部元素是新压入的元素，这时整个另一个队列就是按照正常压入顺序
//                  进行逆置后的队列，再将另一个队列全部复制到原来的队列中，这时头部元素的值就是新压入的元素，使得弹出pop操作时间复杂度为O(1),
//使用一个队列来实现，压入O(N), 弹出O(1)，其实就是在压入一个元素后，将整个队列逆置，这时新压入的元素在队列的首部，弹出时，直接弹出头部元素即可


class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() 
    { }
    
    /** Push element x onto stack. */
    void push(int x) {
        _queue.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        vector<int> helper;
        int n = _queue.size();
        for (int i = 0; i < n - 1; ++i)
        {
            helper.push_back(_queue.front());
            _queue.pop();
        }
       // cout << "size: " << _queue.size() << endl;
        int ret = _queue.back();
        _queue.pop();
        for (auto elem : helper)
        {
            //cout << "helper: " << elem << " ";
            _queue.push(elem);
        }
        //cout << endl;

        return ret;
    }
    
    /** Get the top element. */
    int top() {
        return _queue.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return _queue.empty();
    }
private:
    queue<int> _queue;

};

int main(void)
{
    MyStack my_stack;
    my_stack.push(1);
    my_stack.push(2);
    my_stack.push(3);
    cout << my_stack.pop() << endl;
    cout << my_stack.pop() << endl;
    cout << my_stack.pop() << endl;
    cout << my_stack.empty() << endl;




    return 0;
}