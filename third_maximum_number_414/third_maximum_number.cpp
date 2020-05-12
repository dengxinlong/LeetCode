#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <set>

using namespace std;

//暴力破解，先寻找最大的数，然后寻找第二大的数，最后寻找第三大的数
class Solution
{
public:
    int thirdMax(vector<int> & nums)
    {
        int min_val, mid_val, max_val;
        min_val = numeric_limits<int>::min();
        mid_val = numeric_limits<int>::min();
        max_val = numeric_limits<int>::min();
        int cnt = 0;

        //找到第一大的数
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > max_val)
                max_val = nums[i];
       
       //找到第二大的数
        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] > mid_val && nums[i] != max_val)
                mid_val = nums[i];

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] >= min_val && nums[i] != max_val && nums[i] != mid_val)
            {
                min_val = nums[i];
                cnt++;
            }
                
        return cnt == 0 ? max_val : min_val;
    }
};


//排序法，先将数组排好序，然后直接输出第三大的数即可
// class Solution 
// {
// public:
//     int thirdMax(vector<int> & nums) 
//     {   
//         sort(nums.begin(), nums.end(), greater<int>());
//         for (auto elem : nums)
//             cout << elem << " ";
//         cout << endl;
//         int cnt = 1;
//         for (int i = 1; i < nums.size(); i++)
//         {
//             if (nums[i] < nums[i - 1])
//             {
//                 cnt++;
//                 if (cnt == 3)
//                     return nums[i];
//             }
//         }
//         return nums[0];
//     }
// };

//解法二
//这里的解法参考了leetcode中网友的解答,利用红黑树来解决
// class Solution
// {
// public:
//     int thirdMax(vector<int> & nums)
//     {
//         set<int> max_nums;
//         for (const auto elem : nums)
//         {
//             max_nums.insert(elem);
//             if (max_nums.size() > 3)
//                 max_nums.erase(max_nums.begin());
//         }
//         vector<int> temp;
//         temp.reserve(3);
//         for (auto elem : max_nums)
//             temp.push_back(elem);

//         if (temp.size() < 3)
//         {
//            return *(temp.end() - 1);
//         }
            
//         return *max_nums.begin();
//     }
// };

int main(void)
{
    Solution so;
    vector<int> vec{1,2,-2147483648};
    cout << so.thirdMax(vec) << endl;

    return 0;
}
