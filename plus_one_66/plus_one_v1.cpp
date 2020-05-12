/*
 *说明：本题是leetcode中的第66题
 *描述：Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 *      The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 *      You may assume the integer does not contain any leading zero, except the number 0 itself.
 */

/*
 *说明：这里解题方法和我们版本的有一些区别，上一个版本不管什么情况，直接编译整个vector，这里稍微优化一下
 */

#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    vector<int> plusOne(vector<int> & digits) 
    {
        int length = digits.size();
        int flag;
        vector<int> tmp = digits;
        if (tmp[length - 1] != 9)
        {
            tmp[length - 1] += 1;
            return tmp;
        }
        else
        {
            flag = 1;
            for (int i = length - 1; i > 0; --i)
            {
                if (tmp[i] + flag > 9)
                {
                    tmp[i] = 0;
                    flag = 1;
                }
                else
                {
                    tmp[i] += flag;
                    flag = 0;
                    break;
                }     
            }
        }

        //digits[0]单独处理
        if (tmp[0] + flag > 9)
        {
            tmp[0] = 0;
            tmp.insert(tmp.begin(), 1);
        }
        else
        {
            tmp[0] += flag;
        }

        return tmp;
    }
};

int main(void)
{
    vector<int> val{9};
    Solution so;
    
    vector<int> ret = so.plusOne(val);

    for (auto elem : ret)
    {
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}