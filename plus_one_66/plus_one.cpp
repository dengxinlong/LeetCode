/*
 *说明：本题是leetcode中的第66题
 *描述：Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
 *      The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
 *      You may assume the integer does not contain any leading zero, except the number 0 itself.
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
        int flag = 0;
        int end_val = digits[digits.size() - 1] + 1;
        if (end_val > 9)
        {
            end_val = 0;
            flag = 1;
        }
        digits[digits.size() - 1] = end_val;   
        if (digits.size() == 1 && flag == 1)
        {
            digits.insert(digits.begin(), 1);
            return digits;
        }

        for (int i = digits.size() - 2; i > 0; --i)
        {
            if (digits[i] + flag > 9)
            {
                digits[i] = 0;
                flag = 1;
            }
            else
            {
                digits[i] += flag;
                flag = 0;
                break;
            }     
        }

        //digits[0]单独处理
        if (digits[0] + flag > 9)
        {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        else
        {
            digits[0] += flag;
        }

        return digits;
    }
};

int main(void)
{
    vector<int> val{9};
    Solution so;
    
    so.plusOne(val);

    for (auto elem : val)
    {
        cout << elem << " ";
    }
    cout << endl;
    
    return 0;
}