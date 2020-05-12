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

        vector<int> tmp;
        vector<vector<int>> val;
        for (int i = 1; i <= rowIndex + 1; ++i)
        {
            tmp.resize(i);
            for (int j = 1; j <= i; ++j)
            {
                if (j == 1 || j == i)
                {
                    tmp[j - 1] = 1;
                }
                else
                {
                    tmp[j - 1] = val[i - 2][j - 1] + val[i - 2][j - 2];
                }
            }
            val.push_back(tmp);
            for (auto elem : tmp)
                cout << elem << " ";
            cout << endl;
        }
        
        return val[rowIndex];
    }
};


int main(void)
{
    Solution so;
    vector<int> val = so.getRow(5);

    cout << "------------" << endl;
    for (const auto & i : val)
    {
        cout << i << " ";
        
    }
    cout << endl;
    return 0;
}