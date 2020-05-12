#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//排序法
//先把数组中的元素排序，然后元素之间前后比较，如果有两个相邻元素相差大于1，则后面的元素减 1 就是需要找到的元素
// class Solution
// {
// public:
//     int missingNumber(vector<int> & nums)
//     {
//         sort(nums.begin(), nums.end());
//         if (nums[0] != 0)
//             return 0;
//         else if ( nums[nums.size() - 1] != nums.size())
//             return nums.size();

//         for (int i = 1; i < nums.size(); ++i)
//         {
//             if (nums[i] - nums[i - 1] > 1)
//                 return nums[i] - 1;
//         }
        
//         return -1;
//     }
// };

//解法一：通过hash_table来存储数组中的元素，之后在该结构中进行查找
// class Solution 
// {
// public:
//     int missingNumber(vector<int> & nums) 
//     {
//         unordered_set<int> temp;
//         for (auto elem : nums)
//             temp.insert(elem);
//         for (int i = 0; i <= nums.size(); ++i)
//             if (temp.find(i) == temp.end())
//                 return i;
//     }
// };


//求和法
//这里的解法可以说参考了高斯的智慧，我们知道，0....n，总共n + 1个数相加，
//结果可以用等差数列求和，既然0....n中缺少了一个数，那么我们直接对数组中的元素求和，二者相减，就是结果
// class Solution
// {
// public:
//     int missingNumber(vector<int> & nums)
//     {
//         int sum = nums.size() * (nums.size() + 1) / 2;
//         int ret = 0;
//         for (int i = 0; i < nums.size(); i++)
//             ret += nums[i];
//         return sum - ret;
//     }
// };

//位运算法
class Solution
{
public:
    int missingNumber(vector<int> & nums)
    {
        int missing_val = nums.size();
        for (int i = 0; i < nums.size(); ++i)
        {
            missing_val ^= i ^ nums[i];
        }
        return missing_val;
    }
};


int main(void)
{
    Solution so;
    vector<int> nums{3,0,1};
    cout << so.missingNumber(nums) << endl;

    return 0;
}