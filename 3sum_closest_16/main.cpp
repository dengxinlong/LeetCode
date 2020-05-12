#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;


//暴力破解
//三重循环求解       时间复杂度：O(N * 3); 空间复杂度：O(1)
// class Solution 
// {
// public:
//     int threeSumClosest(vector<int> & nums, int target) 
//     {
//         if (nums.size() < 3)
//             return numeric_limits<int>::max();
//         int ret = nums[0] + nums[1] + nums[2];
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             for (int j = i + 1; j < nums.size(); ++j)
//             {
//                 for (int k = j + 1; k < nums.size(); ++k)
//                 {
//                     int cur_ret = nums[i] + nums[j] + nums[k];
//                     ret = abs(cur_ret - target) < abs(ret - target) ? cur_ret : ret;
//                 }
//             }
//         }

//         return ret;
//     }
// };

//对代码进行一定程度的优化，先将数组中的元素排序，然后再第三重循环中采用二分查找，时间复杂度O(N^2 * logN), 空间复杂度: O(1)
class Solution
{
public:
    int threeSumClosest(vector<int> & nums, int target) 
    {
        if (nums.size() < 3)
            return numeric_limits<int>::max();

        sort(nums.begin(), nums.end());

        int ret = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                //二分查找
                int low = j + 1, high = nums.size() - 1;
                while (low < high)
                {
                    //......   
                }
            }
        }
    }
};
//上述代码不行，因为在利用二分查找时，在判断中位数时，不能排除一部分元素，因为不能保证那边的元素更加接近target
class Solution
{
public:
    jint threeSumClosest(vector<int> & nums, int target)
    {
        
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{-1, 2, 1, -4};
    int target = 1;

    cout << so.threeSumClosest(nums, target) << endl;

    return 0;
}