/*
 *说明：本题为leetcode中的第122题，仍然是关于股票问题
 *描述：Say you have an array for which the ith element is the price of a given stock on day i.
 *Design an algorithm to find the maximum profit. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).
 *Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
 */

/*
 *解题思路：本题的解题思路和上一题的相似，可以参考上一题的解题思路，根据题目意思，其实就是需要找到上升的的线段，然后得出所能获得的利润
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
    int maxProfit( vector<int>& prices ) 
    {
        //int pre_minprice;
        int minprice = std::numeric_limits<int>::max();
        int maxprice = std::numeric_limits<int>::min();
        int maxprofit = 0;

        for ( int i = 0; i < prices.size();)
        {
            //求出每个上升区域的最低点和最高点
            
            while (i < prices.size() && prices[i] < minprice)
            {
                minprice = prices[i++];
                maxprice = minprice;
            }
                
            
            while ( i < prices.size() && prices[i] > maxprice )
            {
                maxprice = prices[i++];
            }
                
            //cout << minprice << " " << maxprice << endl;
            maxprofit += maxprice - minprice;
            minprice = maxprice;
        }

        return maxprofit;   
    }
};

int main(void)
{
    Solution so;
    vector<int> vec{7,1,5,3,6,4};

    int max = so.maxProfit(vec);
    cout << max << endl;


    return 0;
}