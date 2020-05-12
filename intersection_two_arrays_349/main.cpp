#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//暴力破解，，其实就是求解一个数组中的数是否在另一个数组中出现
// class Solution 
// {
// public:
//     vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
//     {
//         if (!nums1.size() || !nums2.size())
//             return vector<int>();
//         vector<int> ret;
//         for (auto elem : nums1)
//         {
//             for (auto item : nums2)
//             {
//                 if (elem == item)
//                 {
//                     ret.push_back(elem);
//                     break;
//                 }
                    
//             }
//         }
//         //因为在数组中可能存在相同的元素，需要将这些元素删除
//         sort(ret.begin(), ret.end());
//         int i, j;
//         for (i = 0, j = 1; j < ret.size(); j++)
//         {
//             if (ret[i] != ret[j])
//                 ret[++i] = ret[j];
//         }
 
//         if (ret.begin() + i + 1 != ret.end() && ret.size() > 0)
//             ret.erase(ret.begin() + i + 1, ret.end());
        
//         return ret;
//     }
// };

//通过hash_table来解决
class Solution
{
public:
    vector<int> intersection(vector<int> & nums1, vector<int> & nums2)
    {
        unordered_set<int> index;
        unordered_set<int> ret;
        for (auto elem : nums2)
            index.insert(elem);
        for (auto elem : nums1)
        {
            
            if (index.find(elem) != index.end())
                ret.insert(elem);
        }

        vector<int> res;
        for (auto elem : ret)
            res.push_back(elem);

        return res;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums1{4,3,9,3,1,9,7,6,9,7}, nums2{5,0,8};
    vector<int> ret = so.intersection(nums1, nums2);
    for (auto elem : ret)
        cout << elem << endl;


    return 0;
}