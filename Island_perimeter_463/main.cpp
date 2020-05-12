#include <iostream>
#include <vector>

using namespace std;

//直接遍历整个数组，只有前面有相邻的方格， 周长就减2
class Solution 
{
public:
    int islandPerimeter(vector<vector<int>> & grid)
    {
        int ret = 0; 
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j])
                {
                    ret += 4;
                    if (j > 0 && grid[i][j - 1])
                        ret -= 2;
                    if (i > 0 && grid[i - 1][j])
                        ret -= 2;
                }
                
            }
        }
        return ret;
    }
};


int main(void)
{
    Solution so;
    vector<vector<int>> grid{{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}};
    cout << so.islandPerimeter(grid) << endl;


    return 0;
}