#include <iostream>
#include <vector>

using namespace std;


//开辟一定空间，用于存放非 0 的元素，而后将该数组中的元素依次复制到数组nums中，最后为nums数值中填充0
// class Solution
// {
// public:
//     void moveZeroes(vector<int> & nums)
//     {
//         vector<int> ret;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             if (nums[i] != 0)
//                 ret.push_back(nums[i]);
//         }

//         // for (int i = 0; i < nums.size(); ++i)
//         // {
//         //     if (i > ret.size() - 1)
//         //         nums[i] = 0;
//         //     else
//         //         nums[i] = ret[i];
//         // }
//         int size = nums.size();
//         nums = ret;
//         for (int i = ret.size(); i < size; i++)
//             nums.push_back(0);
//     }
// };


//这题和之前的删除有序数组中的重复元素一样的思路，双指针(快慢指针)
// class Solution 
// {
// public:
//     void moveZeroes(vector<int> & nums) 
//     {
//         int i = 0, j = i;
//         for (; j < nums.size(); ++j)
//         {
//             if (nums[j] != 0)
//                 nums[i++] = nums[j];
//         }
//         //对剩余的数组部分补充0
//         for (; i < nums.size(); ++i)
//             nums[i] = 0;
//     }
// };

//这里的解法主要是对上面的方法的一个局部优化，比如当数组中最后一个数是非0，而前面的数字都是0，在对数组补充0的时候多了许多不必要的操作
//现在的算法就是对这一部分进行优化
class Solution
{
public:
    void moveZeroes(vector<int> & nums)
    {
        for (int i = 0, j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != 0)
                swap(nums[j], nums[i++]);
        }
    }
};

int main(void)
{
    Solution so;
    vector<int> vec{0,1,0,3,12};

    so.moveZeroes(vec);
    for (auto elem : vec)
        cout << elem << " ";
    cout << endl;


    return 0;
}