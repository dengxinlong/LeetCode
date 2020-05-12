#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <list>

using namespace std;

//长键输入，指的是当我们输入一个字符串时，可能某个字符会多输入几次，但是一定不会少输入。满足这样条件的字符串就是长键输入，返回true

//本质上来说，这题只是给了一个场景而已，转化为稍微抽象一点的问题就是
//给定两个字符串，这两个字符串满足这样一个条件：
//            B字符串中每个连续字符的个数(一个字符可以看成是连续的)要大于等于A中每个连续字符的个数；且相比较的字符是相同的字符


//方法一：分块存储，对于name和typed字符串，对连续的字符(包括只出现一次的字符)记录其次数，这样对两个索引的值进行一一比较
//时间复杂度：O(N + M), 空间复杂度O(N + M)
// class Solution 
// {
// public:
//     bool isLongPressedName(string name, string typed) 
//     {
//         list<pair<char, int>> name_idx;
//         list<pair<char, int>> typed_idx;   //构造两个索引链表
        
//         name_idx.push_back(make_pair(name[0], 1));
//         for (int i = 1; i < name.size(); ++i)
//         {
//             if (name[i] != name[i - 1])
//                 name_idx.push_back(make_pair(name[i], 1));
//             else
//                 name_idx.back().second++;
//         }

//         // for (auto elem : name_idx)
//         //     cout << elem.first << ": " << elem.second << " "; 
//         // cout << endl;
//         typed_idx.push_back(make_pair(typed[0], 1));
//         for (int i = 1; i < typed.size(); ++i)
//         {
//             if (typed[i] != typed[i - 1])
//                 typed_idx.push_back(make_pair(typed[i], 1));
//             else
//                 typed_idx.back().second++;
            
//         }

//         //建立好上面的索引链表后，分别遍历上述两个链表，
//         auto name_iter = name_idx.begin(), typed_iter = typed_idx.begin();
//         while (name_iter != name_idx.end() && typed_iter != typed_idx.end())
//         {
//             if (name_iter->first != typed_iter->first || name_iter->second > typed_iter->second)
//                 return false;
//             name_iter++;
//             typed_iter++;
//         }

//         if (name_iter != name_idx.end() || typed_iter != typed_idx.end())
//             return false;

//         return true;
//     }
// };

//双指针法
//时间复杂度：O(N + M), 空间复杂度O(1)
class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        if (name.size() > typed.size())
            return false;
        int name_i = 0, name_j = 1, typed_i = 0, typed_j = 1;
        while (name_j < name.size() && typed_j < typed.size())
        {
            while (name_j < name.size() && name[name_j] == name[name_i])
                name_j++;
            while (typed_j < typed.size() && typed[typed_j] == typed[typed_i])
                typed_j++;
            if (name[name_i] != typed[typed_i] || (name_j - name_i) > (typed_j - typed_i))
                return false;
            name_i = name_j;
            typed_i = typed_j;
        }

        if (name_j < name.size())
            return false;
        
        while (typed_j < typed.size())
        {
            if (typed[typed_j++] != typed[typed_i - 1])
                return false;
        }

        return true;
    }
};

int main(void)
{
    string name{"leetcode"}, typed{"lleeetcodedddd"};
    Solution so;
    cout << so.isLongPressedName(name, typed) << endl;



    return 0;
}