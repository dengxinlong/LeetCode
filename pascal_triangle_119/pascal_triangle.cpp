/*
 *说明：本题是leetcode中的第119题，关于杨辉三角的问题
 *描述：Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
        Note that the row index starts from 0.
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    vector<int> getRow(int rowIndex) 
    {
        if (rowIndex == 0)
        {
            vector<int> vec{1};
            return vec;
        }

        vector<int> pre_vec;
        vector<int> cur_vec;
        for (int i = 1; i <= rowIndex + 1; ++i)
        {
            //cout << "i = " << i << endl;
            for (int j = 1; j <= i; ++j)
            {
                //cout << "j = " << j << endl;
                if (j == 1 || j == i)
                    cur_vec.push_back(1);
                else
                    cur_vec.push_back(pre_vec[j - 2] + pre_vec[j -1]);   
            }

            // for (auto elem : cur_vec)
            //     cout << elem << " ";
            // cout << endl;

            pre_vec = cur_vec;
            cur_vec.resize(0);
        }
        return pre_vec;
    }
};

int main(void)
{
    Solution so;
    vector<int> vec = so.getRow(2);
    
    for (auto elem : vec)
        cout << elem << " ";
    cout << endl;

    return 0;
}