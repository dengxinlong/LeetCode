/*
 *题目：两数之和
 *描述：Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *      You may assume that each input would have exactly one solution, and you may not use the same element twice.
 */
/*解题思路：利用unordermap来解决问题，
 *          首先想到的解法是暴力破解法，但暴力破解法的时间复杂度是(n^2)，
 *          这显然不是我们想要的解决方法，问题就在于我们需要遍历后面的元素
 *          时间复杂度为o(n)，这里可以进行优化操作，如果能将这里的时间复杂度降下来
 *          问题就解决了，我们可以使用unordermap来保存每一个元素的索引和值，这时查找符合元素
 *          值的时候，时间复杂度为o(1)
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>

using std::cout;
using std::cin;
using std::vector;
using std::unordered_map;
using std::map;


class Solution 
{
public:
    Solution() {}

    vector<int> twoSum(vector<int> & nums, int target) 
    {
        if (nums.size() <= 1)
        {
            return vector<int>();
        }

        //建立索引和值的hash_map结构
        unordered_map<int, int> index_val;
        //map<int, int> index_val;
        for (int i = 0; i < nums.size(); ++i)
        {
            index_val.insert(std::make_pair(nums[i], i));
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            auto iter = index_val.find(target - nums[i]);
            if (iter != index_val.end() && iter->second != i)
            {
                vector<int> vec{i, iter->second};
                return vec;
            }
        }
    }
};


int main(void)
{
    Solution so;
    vector<int> vec{3, 2, 4};
    vector<int> ret = so.twoSum(vec, 6);

    for (auto elem : ret)
    {
        cout << elem << " ";
    }
    cout << std::endl;


    return 0;
}
