#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//这题比较好理解，给定的数组是一个山脉数组，即在该数组中只有一个极值点，按照数学上面说，该数组中只有一个极值点，
// 即在该极值点的左侧单调递增，在右侧单调递减，我们需要做的就是找到该下标

//解法1：直接查找
// class Solution 
// {
// public:
//     int peakIndexInMountainArray(vector<int>& A) 
//     {
//         if (A.size() < 3)
//             return 0;
//         int i = 0; 
//         while (A[i] < A[i + 1])
//         {
//             i++;
//         }
//         return i;
//     }
// };

//其实就是需要找到该数组中最大值所对应的下标
// class Solution
// {
// public:
//     int peakIndexInMountainArray(vector<int>& A) 
//     {
//         int ans = 0;
//         for (int i = 1; i < A.size(); ++i)
//         {
//             if (A[i] > A[ans])
//                 ans = i;
//         }

//         return ans;
//     }
// };

//二分查找
class Solution
{
public:
    int peakIndexInMountainArray(vector<int> & A)
    {
        int low = 0, high = A.size() - 1;
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (A[mid] < A[mid + 1])
                low = mid + 1;
            else
                high = mid;
        }

        return low;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{1, 2, 4, 2, 1};
    
    cout << so.peakIndexInMountainArray(nums) << endl;

    return 0;
}