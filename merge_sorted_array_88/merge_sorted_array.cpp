/*
 *说明：本题是leetcode中的第88题，题目是合并两个有序数组
 *描述：Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
 */

/*
 *思路：两个有序数组的合并，直接两个索引分别指向两个数组即可，然后遍历这两个数组
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) 
    {
        vector<int> tmp;
        //tmp.reserve(m + n);
        int k = 0, i = 0, j = 0;
        for (;i < m && j < n;)
        {
            if (nums1[i] < nums2[j])
            {
                //tmp[k] = nums1[i++];
                tmp.push_back(nums1[i++]);
            }
            else
            {
                tmp.push_back(nums2[j++]);
                //tmp[k] = nums2[j++];
            }
        }

        while (i < m)
        {
            //tmp[k++] = nums1[i++];
            tmp.push_back(nums1[i++]);
        }
        while (j < n)
        {
           // tmp[k++] = nums2[j++];
            tmp.push_back(nums2[j++]);
        }

        for (int i = 0; i < tmp.size(); ++i)
        {
            nums1[i] = tmp[i];
        }
    }
};

int main(void)
{
    Solution so;
    vector<int> val1{1, 3, 4, 5, 0, 0, 0}, val2{2, 6, 7};
    so.merge(val1, 4, val2, val2.size());

    for (auto elem : val1)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}