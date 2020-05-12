#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;


//暴力破解法，直接从数组中进行寻找，只是需要注意的是，因为k_diff对中的数是不能重复的，所以需要将已经找到的 k_diff 对存入hash_set中，防止重复
class Solution 
{
public:
    int findPairs(vector<int>& nums, int k) 
    {
        if (k < 0)
            return 0;
        int cnt = 0;
        unordered_set<int> sets;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            unordered_set<int> sets2;
            for (int j = i + 1; j < nums.size() && !sets.count(nums[i]); ++j)
            {
                
                if (abs(nums[i] - nums[j]) == k)
                {
                    if (!sets.count(nums[j]) && !sets2.count(nums[j]))
                    {
                        cnt++;
                        sets.insert(nums[i]); 
                        sets2.insert(nums[j]);
                    }
                }   
                
            }
        }
        for (auto elem : sets)
            cout << elem << " ";
        cout << endl;

        return cnt;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{1,1,1,2,1};
    cout << so.findPairs(nums, 1) << endl;

    return 0;
}