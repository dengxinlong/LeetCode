#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//排序法
class Solution 
{
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[n - 1] * nums[0] * nums[1]);
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{-4,-3,-2,-1,60};
    cout << so.maximumProduct(nums) << endl;


    return 0;
}