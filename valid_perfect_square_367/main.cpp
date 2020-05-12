#include <iostream>
#include <vector>

using namespace std;

//判断一个数是否是完全平方数
//这里需要普及一个数学知识，一个数如果是完全平方数，则这个数的一半的数前面奇数( > 1) 的和等于该num
// class Solution 
// {
// public:
//     bool isPerfectSquare(int num) 
//     {   
//         return (num / 4) * (num / 4) == num;
//     }
// };


//暴力破解法
// class Solution
// {
// public:
//     bool isPerfectSquare(int num)
//     {
//         if (num == 1 || num == 0)
//             return true;
//         for (long i = 1; i <= num / 2; ++i)
//         {
//             if (num == i * i)
//                 return true;
//         }

//         return false;
//     }
// };


//二分查找法
//首先，我们在遍历num/2之前，这些数构成的是有序序列，这样我们直接就可以采用二分查找法
class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        if (!num)
            return true;
        long low = 1, high = num / 2, mid;
        while (low < high)
        {
            mid = low + (high - low + 1) / 2; //这里应该选择右中位数，因为后面的排除一半数的代码中，low在某些情况下是不收缩的
            if (mid * mid > num)
                high = mid - 1;
            else
                low = mid;
        }

        return low * low == num;
    }
};

int main(void)
{
    Solution so;
    int num = 16;
    cout << so.isPerfectSquare(num) << endl;


    return 0;
}