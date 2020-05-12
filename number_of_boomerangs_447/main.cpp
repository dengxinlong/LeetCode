#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

//本题也可以采用暴力破解，但是时间复杂度非常高，为O(n*3)，这里就不采用该方法了
//下面的hash_table其实就是在暴力破解的基础上进行优化的，因为在暴力破解中，存在着大量的重复计算，这时，我们使用hash_table把中间计算的结果保存下来，然后进行判断

//hash_map求解
class Solution 
{
public:
    int numberOfBoomerangs(vector<vector<int>>& points) 
    {
        unordered_map<int, int> hash_map;
        int distance = 0, ret = 0;
        for (int i = 0; i < points.size(); ++i)
        {
            hash_map.clear();
            for (int j = 0; j < points.size(); ++j)
            {
                if (i == j)
                    continue;
                distance = (points[j][0] - points[i][0]) * (points[j][0] - points[i][0]) \
                         + (points[j][1] - points[i][1]) * (points[j][1] - points[i][1]);
    
                if (hash_map.find(distance) != hash_map.end())
                    ret += hash_map[distance] * 2;
                
                hash_map[distance]++;
            }
        }

        return ret;
    }
};

int main(void)
{
    Solution so;
    vector<vector<int>> points;
    points.push_back(vector<int>{0, 0});
    points.push_back(vector<int>{1, 0});
    points.push_back(vector<int>{2, 0});

    vector<vector<int>> nums{{0, 0}, {1, 0}, {2, 0}};
    for (auto point: nums)
    {
        for (auto elem : point)
            cout << elem << ", ";
        cout << endl;
    }
    
    cout << so.numberOfBoomerangs(points) << endl;


    return 0;
}