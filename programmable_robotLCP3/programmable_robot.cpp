#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution 
{
public:
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) 
    {
        sort(obstacles.begin(), obstacles.end());
        vector<int> position{0, 0};
        while (true)
        {
            for (auto elem : command)
            {
                if (position[0] == x && position[1] == y)
                    return true;
                if (position[0] > x || position[1] > y)
                    return false;
                if (elem == 'U')            //向 y 轴前进一步
                {
                    position[1] += 1;
                }
                else                    //向 x 轴前进一步
                {
                    position[0] += 1;
                }
                // for (auto elem : position)
                //     cout << elem << " ";
                // cout << endl;

                auto iter = find(obstacles.begin(), obstacles.end(), position);   //find函数这里需要改进
                if (iter != obstacles.end())
                {
                    return false;
                }
            }
        }
    }
};

int main(void)
{
    vector<vector<int>> vec{vector<int>{10, 5}, vector<int>{1, 6}, vector<int>{6, 10}, vector<int>{3, 0}, vector<int>{0, 3}, vector<int>{0, 10},
                            vector<int>{6, 2}};
    
    // for (auto elem1 : vec)
    // {
    //     for (auto elem2 : elem1)
    //     {
    //         cout << elem2 << " ";
    //     }
    //     cout << endl;
    // }
    Solution so;
    cout << so.robot("RUUR", vec, 7856, 9033) << endl;

    return 0;
}