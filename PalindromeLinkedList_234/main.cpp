#include "List.h"

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

//判断一个链表是否是回文链表
class PalindromeLinkedList
{
public:
    //方法一：根据回文的思想，利用栈结构，时间复杂度O(N)，空间复杂度O(N)
    static bool judgePalindrome_1(ListNode * head)
    {
        stack<ListNode *> helpStack;
        for (ListNode * ptr = head; ptr; ptr = ptr->next) {
            helpStack.push(ptr);
        }
        while (head) {
            if (helpStack.top()->val != head->val) return false;
            helpStack.pop();
            head = head->next;
        }
        return true;


        // int length = 0;
        // ListNode * ptr = head;
        // while (ptr)             //计算整个链表的长度
        // {
        //     length++;
        //     ptr = ptr->next;
        // }
        // ptr = head->next;
        // ListNode * pnew = nullptr;
        // ListNode * pre = head;
        // ListNode * headNew = nullptr;
        // for (int i = 0; i <= length / 2 && ptr; i++)
        // {
        //     headNew = ptr->next;
        //     //ListNode * s = ptr->next;
        //     pre->next = pnew;
        //     pnew = pre;
        //     pre = ptr;
        //     ptr = ptr->next;
        // }
    }

    //方法二：方法一是将整个链表都压入栈中，其实不用，只需要压入链表的前半部分元素即可
    static bool judgePalindrome_2(ListNode * head)
    {
        if (!head || !head->next) return true;

        stack<ListNode *> helpStack;
        ListNode * slow = head;
        ListNode * faster = head;
        while (faster && faster->next) {
            helpStack.push(slow);
            slow = slow->next;
            faster = faster->next->next;
        }
        // printStack(helpStack);
        slow = faster ? slow->next : slow;
        // printList(slow);
        while (slow) {
            if(helpStack.top()->val != slow->val) return false;
            helpStack.pop();
            slow = slow->next;
        }
        return true;
    }

    //利用反转一个单链表的思想，时间复杂度O(N), 空间复杂度O(1)
    static bool judgePalindrome_3(ListNode * head)
    {
        if (!head || !head->next) return true;
        ListNode * slow = head;
        ListNode * faster = head;
        while (faster && faster->next) {
            slow = slow->next;
            faster = faster->next->next;
        }
        reverseLinkList(slow); //将后半部分的链表反转
        faster = slow;  //后面在将该后半部分链表反转回来
        ListNode * ptr = head;
        bool ret = true;
        while (slow) {
            if (ptr->val != slow->val) {
                ret = false;
                break;
            }
            slow = slow->next;
            ptr = ptr->next;
        }

        reverseLinkList(faster);
        printList(head);
        return ret;
    }

private:
    static void reverseLinkList(ListNode * & head)
    {
        if (!head && !head->next) return;
        ListNode * ptr = head->next;
        head->next = nullptr;
        ListNode * right = nullptr;
        while (ptr) {
            right = ptr->next;
            ptr->next = head;
            head = ptr;
            ptr = right;
        }
    }

    static void printStack(stack<ListNode *> helpStack)
    {
        while (!helpStack.empty()) {
            cout << helpStack.top()->val << " ";
            helpStack.pop();
        }
        cout << endl;
    }

    static void printList(ListNode * ptr)
    {
        while (ptr) {
            cout << ptr->val << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
};

int main(void)
{
    vector<int> nums{1, 2, 3, 3, 2, 1};
    ListNode * head = nullptr;
    create_list(&head, nums);
    for (ListNode * ptr = head; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;
    cout << PalindromeLinkedList::judgePalindrome_3(head) << endl;
    return 0;
}

/*
Line 152: Char 16: runtime error: reference binding to misaligned address 0xbebebebebebec0b6 for type 'ListNode *', which requires 8 byte alignment (stl_deque.h)
0xbebebebebebec0b6: note: pointer points here
<memory cannot be printed>
SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior /usr/bin/../lib/gcc/x86_64-linux-gnu/8/../../../../include/c++/8/bits/stl_deque.h:162:16
*/