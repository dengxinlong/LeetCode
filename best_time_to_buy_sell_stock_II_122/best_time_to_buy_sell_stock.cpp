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
        int minprice = std::numeric_limits<int>::max();
        int pre_minprice;
        int maxprofit = 0;

        for ( int i = 0; i < prices.size(); ++i )
        {
            if ( prices[i] < minprice )           //此时股票的走势呈现下降的趋势，这时找到最低点
                minprice = prices[i];
            else    //此时股票呈现上升趋势
            {
                //if (maxprofit < prices[i] - minprice)
                maxprofit += prices[i] - minprice;
                minprice = prices[i];
                
            }
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


//现在的想法，其实就是找到数组中递增的序列，分段相加即可，就是所求的答案