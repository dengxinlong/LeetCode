/*
 *说明：本题是leetcode中的第118题，和杨辉三角有关的问题
 *描述：Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
 */

/*
 *思路：本题就是利用第一行来生成下面的一行，然后依次生成后面行，可以看成是动态规划问题
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    vector<vector<int>> generate(int numRows) 
    {
        if (numRows == 0)       //如果要求输出 0 行杨辉三角，则直接返回空的数组即可
            return vector<vector<int>>();
        
        vector<vector<int>> val;     //杨辉三角最终存储的空间
        vector<int> tmp;            //每一行杨辉三角存储的空间
        if (numRows == 1)
        {
            tmp.push_back(1);
            val.push_back(tmp);
            return val;
        }
        
        for (int i = 1; i <= numRows; ++i)
        {
            tmp.resize(i);     //重置每行tmp的大小，便于后面的操作
            for (int j = 1; j <= i; ++j)
            {
                if (j == 1 || j == i)           //每一行的第一个元素以及最后一个元素，值为1
                    tmp[j - 1] = 1;
                else
                {
                    tmp[j - 1] = val[i - 2][j -1] + val[i - 2][j - 2];
                }
            }
            val.push_back(tmp);    
        }
        return val;
    }
};

int main(void)
{
    Solution so;
    vector<vector<int>> val = so.generate(5);

    cout << "------------" << endl;
    for (const auto & i : val)
    {
        for (const auto & j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}