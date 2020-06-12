#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//此题根据网友的提示，有点像田忌赛马的情况，对数组中的元素进行分组，每个分组中只有两个元素，同时取各个分组后的元素的最小值，把各个最小值进行相加，使得这个和值最大
class Solution
{
public:
    int arrayPairSum(vector<int> & nums)
    {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];

        return sum;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{1,4,3,2};
    cout << so.arrayPairSum(nums) << endl;


    return 0;
}