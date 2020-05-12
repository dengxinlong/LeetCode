/*
 *说明：本题是leetcode中的第121题，是一道动态规划的题
 *描述：Say you have an array for which the ith element is the price of a given stock on day i.
 *      If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
 *      Note that you cannot sell a stock before you buy one.
 */

/*
 *思路：上一个版本中使用的是暴力破解，时间复杂度为O(N ^ 2)，这里可以看出来，将该代码放入leetcode中运行，时间为1000多毫秒，比较搞笑，所以这个版本尝试进行优化
 *    这里参考了leetcode中的官方解答，一次遍历数组即可，时间复杂度为O(N)。
 */

#include <iostream>
#include <vector>
#include <limits>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int minprice = std::numeric_limits<int>::max();
        int maxprofit = 0;

        for (int i = 0; i < prices.size(); ++i)
        {
            if (prices[i] < minprice)
                minprice = prices[i];
            else if (prices[i] - minprice > maxprofit)
                maxprofit = prices[i] - minprice;
        }
        return maxprofit;
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
