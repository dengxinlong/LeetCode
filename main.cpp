#include "List.h"

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//需要保持相对顺序不变，类似到排序算法中也就是稳定性
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        ListNode * lessHead = nullptr, * lessTail = nullptr;
        ListNode * equalMoreHead = nullptr, * equalMoreTail = nullptr;
        ListNode * next = nullptr;
        while (head) {
            next = head->next;
            head->next = nullptr;
            if (head->val < x) {
                if (!lessHead) {
                    lessHead = lessTail = head;
                } else {
                    lessTail->next = head;
                    lessTail = lessTail->next;
                }
            } else {
                if (!equalMoreHead) {
                    equalMoreHead = equalMoreTail = head;
                } else {
                    equalMoreTail->next = head;
                    equalMoreTail = head;
                }
            }
            head = next;
        }
        // equalMoreTail->next = nullptr;
        if (lessHead) {
            lessTail->next = equalMoreHead;
        }
        return lessHead ? lessHead : equalMoreHead;
    }
};

int main(void)
{
    vector<int> nums{1, 3, 0, 8, 1, 9, -1, 3};
    ListNode * head = nullptr
    create_list(&head, nums);
    int val = 3;
    head = Solution::partition(head, val);
    for (ListNode * ptr = head; ptr; ptr = ptr->next) {
        cout << ptr->val << " ";
    }
    cout << endl;

    return 0;
}