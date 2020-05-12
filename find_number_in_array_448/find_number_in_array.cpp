#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//排序法
//将数组中的元素进行排序，如果两个相邻的元素的差值超过1，则这两个数之间至少有一个没有出现在规定范围内
// class Solution 
// {
// public:
//     vector<int> findDisappearedNumbers(vector<int> & nums) 
//     {
//         if (nums.size() == 0)
//             return vector<int>();
//         vector<int> ret;
//         sort(nums.begin(), nums.end());
   
//         for (int beg = 1, end = nums[0]; beg < end; beg++)
//         {
//             ret.push_back((beg));
//         }
//         for (int i = 1; i < nums.size(); ++i)
//         {
//             for ( int beg = nums[i - 1] + 1, end = nums[i]; beg < end; ++beg)
//                 ret.push_back(beg);
//         }

//         for (int beg = nums[nums.size() - 1] + 1, end = nums.size(); beg <= end; beg++)
//             ret.push_back(beg);
//         return ret;
//     }
// };

//利用hash_table来解答
// class Solution
// {
// public:
//     vector<int> findDisappearedNumbers(vector<int>  & nums)
//     {
//         vector<int> ret;
//         unordered_set<int> sets;
//         for (auto elem : nums)
//         {
//             sets.insert(elem);
//         }
//         for (int i = 1; i <= nums.size(); i++)
//         {
//             if (sets.find(i) == sets.end())
//                 ret.push_back(i);
//         }

//         return ret;
//     }
// };

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int>  & nums)
    {
        vector<int> ret;
        vector<int> temp(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
            temp[abs(temp[i]) - 1] = -abs(temp[abs(temp[i]) - 1]);

        for (int i = 0; i < temp.size(); ++i)
        {
            if (temp[i] > 0)
            {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{4,3,2,7,8,2,3,1};
    vector<int> ret = so.findDisappearedNumbers(nums);
    for (const auto & elem : ret)
        cout << elem << " ";
    cout << endl;

    return 0;
}