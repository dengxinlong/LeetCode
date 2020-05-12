/*
 *说明：本题是leetcode中的第121题，是一道动态规划的题
 *描述：Say you have an array for which the ith element is the price of a given stock on day i.
 *      If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *      Note that you cannot sell a stock before you buy one.
 */

/*
 *思路：暴力破解法，直接遍历整个数组，时间复杂度为O(n ^ 2)
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        if (prices.size() < 2)
            return 0;
        int cur_max = 0, max = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            for (int j = i + 1; j < prices.size(); ++j)
            {
                if (prices[j] - prices[i] > 0)
                {
                    cur_max = prices[j] - prices[i];
                    max = max > cur_max ? max : cur_max;
                }
            }
        }
        return max;
    }
};

int main(void)
{
    Solution so;
    vector<int> vec{7, 6, 4, 3, 1};

    int max = so.maxProfit(vec);
    cout << max << endl;

    return 0;
}
