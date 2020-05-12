#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

//这里直接暴力破解
class Solution 
{
public:
    vector<int> twoSum(vector<int> & nums, int target) 
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if (nums[i] + nums[j] == target)
                {
                    vector<int> vec{i, j};
                    return vec;
                }
            }
        }
        return vector<int>();
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