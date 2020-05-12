/*
 *说明：本题是leetcode中的第219题，仍然是关于数组的题目
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

//解法一：暴力求解
// class Solution 
// {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) 
//     {
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             for (int j = i + 1; j < nums.size(); ++j)
//             {
//                 if (nums[j] == nums[i])
//                 {
//                     if (j - i <= k)
//                         return true;
//                     else
//                         break;
//                 }
//             }
//             return false;
//         }
//     }
// };

// //解法二： hash_map
// class Solution 
// {
// public:
//     bool containsNearbyDuplicate(vector<int>& nums, int k) 
//     {
//         unordered_map<int, vector<int>> elem_cnt;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             elem_cnt[nums[i]].push_back(i);
//             for (int inx = 0; inx < elem_cnt[nums[i]].size() - 1; ++i)
//             {
//                 if (elem_cnt[nums[i]][inx] - elem_cnt[nums[i]][inx] <= k)
//                     return true;
//             }
//             return false;
//         }
//     }
// };

//解法三：这里的解法其实就是解法一的部分优化，主要是维护长度为K的一个窗口，因为我们知道两个相同元素的最大长度要求小于K，所以我们就干脆维护一个长度
//        为K的窗口，
// class Solution
// {
// public:
//     bool containsNearbyDuplicate(vector<int> & nums, int k)
//     {
//         for (int i = 0; i < nums.size(); ++i)
//         {
//            for (int j = max(i - k, 0); j < i; ++j)
//             {
//                if (nums[j] == nums[i])
//                     return true;
//             }
//         }
//         return false;
//     }

// private:
//     int max(int val1, int val2)
//     {
//         return val1 > val2 ? val1 : val2;
//     }
// };

//解法四：这里的解法和上面的解法有点类似，不过上面的解法的窗口由我们手动维护，同时在窗口范围内进行搜索，我们主要耗时就在这上面，
//       所以就想到能不能降低在窗口上的搜索时间，很显然，如果将窗口中的数据放置到hash表中，查找的时间复杂度为O(1)，这样就可以了
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k)
    {
        unordered_set<int> elements;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (elements.find(nums[i]) != elements.end())
                return true;
            else
            {
                elements.insert(nums[i]);
                if (elements.size() > k)
                    elements.erase(nums[i - k]);
            }
        }
        return false;
    }
};


int main(void)
{
    Solution so;
    vector<int> vec{1,2,3,1};
    cout << so.containsNearbyDuplicate(vec, 3) << endl;

    return 0;
}