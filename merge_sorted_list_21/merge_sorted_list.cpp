#include "list_t.h"

#include <iostream>
#include <vector>

using namespace std;



class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {

    }
};

int main(void)
{
    vector<int> nums{8, 7, 6, 5, 4, 3, 2};
    ListNode * list;
    create_list(&list, nums);

    display_list(list);
    return 0;
}