#include <iostream>
#include <vector>

using namespace std;


//说明：这个算法和题目意思不符合，需要修改
class Solution 
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> & M) 
    {
        vector<vector<int>> ret;

        vector<vector<int>> nums;
        
        vector<int> temp;
        int n = M[0].size() + 1;

        for (int i = -1; i < n; i++)
            temp.push_back(0);
        nums.push_back(temp);

        for (auto row : M)
        {
            temp.clear();
            temp.insert(temp.begin(), 0);
            for (auto elem : row)
            {
                temp.push_back(elem);
            }
            
            temp.push_back(0);
            nums.push_back(temp);
        }
        temp.clear();
        for (int i = -1; i < n; i++)
        {
            temp.push_back(0);
        }
        nums.push_back(temp);
        // for (auto row : nums)
        // {
        //     for (auto elem : row)
        //         cout << elem << " ";
        //     cout << endl;
        // }
        
        
        for (int i = 1; i < nums.size() - 1; i++)
        {
            vector<int> values;
            for (int j = 1; j < nums[i].size() - 1; j++)
            {
                int val = (nums[i - 1][j - 1] + nums[i- 1][j] + nums[i - 1][j + 1] \
                         + nums[i][j - 1] + nums[i][j] + nums[i][j + 1] \
                         + nums[i + 1][j - 1] + nums[i + 1][j] + nums[i + 1][j + 1]) / 9;
                values.push_back(val);
            }
            ret.push_back(values);
            
        }
        
        return ret;
    }
};

int main(void)
{
    Solution so;
    vector<vector<int>> M{vector<int>{1,1,1}, vector<int>{1,0,1}, vector<int>{1,1,1}};
    vector<vector<int>> ret = so.imageSmoother(M);
    for (auto row : ret)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }

    return 0;
}