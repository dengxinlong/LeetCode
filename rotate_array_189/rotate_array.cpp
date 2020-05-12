#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//暴力求解，每次都需要移动数组，时间复杂度为O(k * N)
// class Solution 
// {
// public:
//     void rotate(vector<int> & nums, int k) 
//     {
//         for (int i = 0; i < k; ++i)
//         {
//             int val = nums.back();
//             nums.pop_back();
//             nums.insert(nums.begin(), val);
//         }
//     }
// };


//解法二：利用一块空间用于存储要转换的序列，最后将原数组中不需要进行转换的元素复制到临时数组中，最后把临时数组中的元素拷贝到原数组中完成转换操作
// class Solution
// {
// public:
//     void rotate(vector<int> & nums, int k)
//     {
//         vector<int> temp;
//         temp.reserve(nums.size());

//         k %= nums.size();

//         for (int i = k; i > 0; --i)
//         {
//             temp.push_back(nums[nums.size() - i]);
//         }
//         for (int i = 0; i < nums.size() - k; ++i)
//         {
//             temp.push_back(nums[i]);
//         }
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             nums[i] = temp[i];
//         }
//     }
// };

//解法三：反转数组
class Solution
{
public:
    void rotate(vector<int> & nums, int k)
    {
        k %= nums.size();
        reverse(nums, 0, nums.size() - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

private:
    void reverse(vector<int> & nums, int beg, int end)      //反转操作
    {
        while (beg < end)
        {
            int temp = nums[beg];
            nums[beg] = nums[end];
            nums[end] = temp;
            beg++, end--;
        }
    }
};



int main(void)
{
    Solution so;
    vector<int> vec{1, 2,3,4,5,6,7};
    so.rotate(vec, 3);

    for (auto elem : vec)
        cout << elem << " ";
    cout << endl;

    return 0;
}