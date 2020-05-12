#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// //暴力破解
//上面的暴力破解法很显然是错误的，因为如果一个元素在nums1中出现了两次，但是在
//在nums2中只出现了一次，通过上面的代码，最终该元素会出现两次，当答案是只出现一次
//所以如果直接使用暴力破解法进行求解是不行的，问题的关键就在于数组二中的数据会遍历多次，但求两个数组的交集，
//是一一对应的关系，所以可利用这种关系来讨巧
// class Solution 
// {
// public:
//     vector<int> intersect(vector<int> & nums1, vector<int> & nums2) 
//     {
//         vector<int> rets;
//         for (int i = 0; i < nums1.size(); ++i)
//         {
//             for (int j  = 0; j < nums2.size(); ++j)
//             {
//                 if (nums1[i] == nums2[j])
//                 {
//                     rets.push_back(nums1[i]);
//                     nums2[j] = -10086;
//                     break;
//                 }
//             }
//         }
//         return rets;
//     }
// };

//hash_map
// class Solution
// {
// public:
//     vector<int> intersect(vector<int> & nums1, vector<int> & nums2)
//     {
//         unordered_map<int, int> hash_map;
//         vector<int> rets;
//         for (auto elem : nums1)
//         {
//             hash_map[elem]++;
//         }
//         for (auto elem : nums2)
//         {
//             if (hash_map[elem] > 0)
//             {
//                 rets.push_back(elem);
//                 hash_map[elem]--;
//             }
//         }
//         return rets;
//     }
// };


//排序 + 双指针
class Solution
{
public:
    vector<int> intersect(vector<int> & nums1, vector<int> & nums2)
    {
        if (nums1.size() < 0 || nums2.size() < 0)
            return vector<int>();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> rets;
        int k = 0;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = k; j < nums2.size(); j++)
            {
                if (nums1[i] == nums2[j])
                {
                    rets.push_back(nums1[i]);
                    k = j + 1;
                    break;
                }
                if (nums1[i] > nums2[j] && j == nums2.size() - 1)
                {
                    return rets;
                }
                if (nums1[i] < nums2[j])
                {
                    k = j;
                    break;
                }
            }
        }

        return rets;
    }
};


// //上面在排序使用双指针法中，在nums2中查找一个元素采用的是遍历方式，
//因为第二个数组是有序的，显然采用遍历的方式不合适，可以选择在查找过程选择二分查找
// class Solution
// {
// public:
//     vector<int> intersect(vector<int> & nums1, vector<int> & nums2)
//     {
//         if (nums1.size() < 0 || nums2.size() < 0)
//             return vector<int>();
//         sort(nums1.begin(), nums1.end());
//         sort(nums2.begin(), nums2.end());

//         vector<int> rets;
//         int k = 0; 
//         for (int i = 0; i < nums1.size(); ++i)
//         {
//             //这里采用二分查找来在nums2中寻找nums1[i]元素
//             //cout << "i: " << i << " nums1: " << nums1[i] << endl;
//             int low = k, high = nums2.size() - 1, mid;
//             while (low < high)
//             {
//                 mid = low + (high - low) / 2;
//                 if (nums2[mid] < nums1[i])
//                     low = mid + 1;
//                 else
//                     high = mid;
//             }

//             //最后加一个判断是否满足条件
//             //cout << "low: " << low << endl;
//             if (nums2[low] == nums1[i])
//             {
//                 rets.push_back(nums1[i]);
//                 k = low + 1;
//             }
//         }

//         return rets;
//     }
// };


int main(void)
{
    Solution so;
    vector<int> nums1{3, 1, 2}, nums2{1};
    vector<int> rets = so.intersect(nums1, nums2);

    for (auto elem : rets)
        cout << elem << " ";
    cout << endl;

    return 0;
}
