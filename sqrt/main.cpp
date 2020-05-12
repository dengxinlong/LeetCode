#include <iostream>
#include <vector>

using namespace std;

//返回x的平方根
//解法一：暴力破解，x的平方根值不会超过x值的一半，直接遍历即可
// class Solution 
// {
// public:
//     int mySqrt(int x) 
//     {
//         if (x == 0)
//             return 0;
//         int ret = 1; 
//         for (long long i = 1; i <= x / 2; i++)
//         {
//             if (i * i > x)
//                 return ret;
//             else 
//                 ret = i;
//         }

//         return ret;
//     }
// };
//上面的代码理论上是没有问题的，但是需要考虑溢出的问题，因为我们需要对i进行平方，这时可能会发生溢出，所以这里将i声明为long long型，其实这是不太合理的举措

//在上面的解法中，本质上其实是从1遍历到x/2，这时需要遍历的序列是一个有序序列，因此可以考虑使用二分法来求解
//二分法求解
// class Solution
// {
// public:
//     int mySqrt(int x)
//     {
//         if (x <= 1)
//             return x;
//         int ret = 1;
//         long low = 1, high = x / 2;   //在后面的相乘过程中，会发生溢出的情况
//         // while (low <= high)
//         // {
//         //     long mid = low + (high - low) / 2;
//         //     if (mid * mid == x)
//         //         return mid;
//         //     else if (mid * mid > x)
//         //         high = mid - 1;
//         //     else
//         //         low = mid + 1;  
//         // }
//         // return high;

//         while (low < high)
//         {
//             long mid = low + (high - low) / 2;
//             if (mid * mid > x)
//                 high = mid - 1;
//             else
//                 low = mid + 1;
//         }

//         if (low * low <= x)     //这里需要考虑x = 2, 3 的情况以及low * low 相乘是否会溢出问题
//             return low;
//         else
//             return low - 1;

//     }
// };


//这里采用二分法模板
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x <= 1)
            return x;
        long low = 1, high = x / 2, mid = 0;
        while (low < high)
        {
            mid = low + (high - low + 1) / 2;
            if (mid * mid > x)
                high = mid - 1;
            else
                low = mid;
        }

        return (int)low;
    }
};


int main(void)
{
    Solution so;
    int val = 4;

    cout << so.mySqrt(val) << endl; 



    return 0;
}