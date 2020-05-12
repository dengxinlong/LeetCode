#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//暴力破解，其实不用尝试该方法，但是该方法是最基本的思路，很多思路都可以从这个思路中衍生
// class Solution
// {
// public:
//     int singleNumber(vector<int> & nums)
//     {
//         for (int i = 0; i < nums.size(); i++)
//         {
//             int cnt = 1;
//             for (int j = 0; j < nums.size(); j++)
//             {
//                 if (nums[i] == nums[j] && i != j)
//                     cnt++;
//             }
//             cout << cnt << endl;
//             if (cnt == 1)
//                 return nums[i];
//         }
//         return -1;
//     }
// };

//排序法
//直接对数组中的元素进行排序，然后遍历排序后的数组，
// class Solution 
// {
// public:
//     int singleNumber(vector<int>& nums) 
//     {
//         sort(nums.begin(), nums.end());
//         int cnt = 1;
//         int i;
//         for (i = 1; i < nums.size(); i += 2)
//         {
//             if (nums[i] != nums[i - 1])
//                 break;
//         }
//         return nums[i - 1];
//     }
// };

//哈希法
class Solution
{
public:
    int singleNumber(vector<int> & nums)
    {
        unordered_map<int, int> index_set;
        for (int i = 0; i < nums.size(); i++)
        {
            index_set[nums[i]]++;
        }

        for (auto elem : index_set)
        {
            if (elem.second == 1)
                return elem.first;
        }
        return -1;
    }
};

// //位运算法
// class Solution
// {
// public:
//     int singleNumber(vector<int> & nums)
//     {
//         int ret = 0;
//          for (auto elem : nums)
//          {
//              ret ^= elem;
//          }
//          return ret;
//     }
// };

int main(void)
{
    Solution so;
    vector<int> nums{2,2,1};
    cout << so.singleNumber(nums) << endl;


    return 0;
}