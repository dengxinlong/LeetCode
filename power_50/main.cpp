#include <iostream>

using namespace std;

//暴力破解
// class Solution
// {
// public:
//     static double mypower(double x, int n)
//     {
//         if (n == 0)
//             return 1;
//         if ( x == 0 || x == 1)
//             return x;

//         double ret = 1;
//         if (n < 0) {
//             for (int i = 0; i < -n; i++) {
//                 ret *= x;
//             }
//             return 1 / ret;
//         }

//         for (int i = 0; i < n; i++) {
//             ret *= x;
//         }

//         return ret;
//     }
// };

//递归
// class Solution
// {
// public:
//     static double mypower(double x, int n)
//     {
            // if (n == 0) return 1;
            // if (n < 0) return 1 / (myPow(x, -(n + 1)) * x);

            // double ret = myPow(x, n / 2);
            // if (n & 1)
            //     ret *= x;
            // return ret * ret;
//     }
// };

//把上面的递归改写成循环
class Solution
{
public:
    static double mypower(double x, int n)
    {

    }
};

int main(void)
{
    int x = 2, n = 2;
    cout << Solution::mypower(x, n) << endl;

    return 0;
}