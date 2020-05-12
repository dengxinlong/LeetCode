#include <iostream>
#include <vector>

using namespace std;

// class Solution 
// {
// public:
//     vector<vector<int>> matrixReshape(vector<vector<int>> & nums, int r, int c) 
//     {
//         if (!nums.size() || nums.size() * nums[0].size() != r * c)
//             return nums;
//         vector<vector<int>> ret;
//         vector<int> temp;
//         int cnt = 0; 
//         for (auto row : nums)
//         {
//             for (auto elem : row)
//             {
//                 cnt++;
//                 temp.push_back(elem);
//                 if (cnt == c)
//                 {
//                     ret.push_back(temp);
//                     cnt = 0;
//                     temp.clear();
//                 }     
//             }
//         }
//     }
// };

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> & nums, int r, int c)
    {
        if (!nums.size() || nums.size() * nums[0].size() != r * c)
            return nums;
        vector<vector<int>> ret;
        ret.reserve(r * c);
        vector<int> temp;
        temp.reserve(c * r);

        for (auto row : nums)
        {
            for (auto elem : row)
            {
                temp.push_back(elem);
            }
        }

        vector<int> rows;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; ++j)        
            {
                rows.push_back(temp[i * c + j]);
            }
            ret.push_back(rows);
        }
        return ret;
    }
};

int main(void)
{
    Solution so;
    vector<vector<int>> nums{vector<int>{1, 2}, vector<int>{3, 4}};
    vector<vector<int>> ret = so.matrixReshape(nums, 1, 4);


    return 0;
}