#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

//判断一个数是否是快乐数，快乐就完事
//暴力破解：我们暂时不知道一个数如果是快乐数的情况下会循环多少次。但我们可以暴力破解，一个数如果循环100次都无法确定其是不是快乐数，那么就可以断定其不是快乐数
// class Solution 
// {
// public:
//     bool isHappy(int n) 
//     {
//         for (int i = 0; i < 100; ++i)
//         {
//             int ans = 0;
            
//             while (n > 0)
//             {
//                 ans += (n % 10) * (n % 10);
//                 n = n / 10;
//             }
            
//             if (ans == 1)
//                 return true;
//             n = ans;    
//         }
//         return false;
//     }
// };

//如果一个数不是快乐数，那么该数一直循环后，就一定会陷入4 → 16 → 37 → 58 → 89 → 145 → 42 → 20 → 4循环中，这是根据数学证明而得的
// class Solution
// {
// public:
//     bool isHappy(int n)
//     {
//         unordered_set<int> unhappy_nums{4, 16, 37, 58, 89, 145, 42, 20};
//         while (1)
//         {
//             int ret = 0;
//             while (n > 0)
//             {
//                 //cout << ret << endl;
//                 ret += (n % 10) * (n % 10);
//                 n /= 10;
//             }
//             //cout << ret << endl;
//             if (ret == 1)
//                 return true;
//             if (unhappy_nums.find(ret) != unhappy_nums.end())
//                 return false;
//             n = ret;
//         }
//         return false;
//     }
// };

//上面是已知非快乐数会经历的数，如果经历了这些数，那么该数一定不是一个快乐数，但是，如果我们事先不知道这种情况呢，这时通过
//分析可以知道的是，一个非快乐数，一定是陷入循环的，那么陷入循环中必定是在某几个数中一直循环，这时我们可以利用hash_table保存中间运算的结果，如果在下一次的运行
//中，该结果已经出现在hash_table中，那么该数一定是非快乐数
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> nums;
        
        while (1)
        {
            int ret = 0;
            while (n > 0)
            {
                ret += (n % 10) * (n % 10);
                n /= 10;
            }
            if (ret == 1)
                return true;
            if (nums.find(ret) != nums.end())
                return false;
            nums.insert(ret);
            n = ret;
        }
    }
};


int main(void)
{
    Solution so;
    cout << so.isHappy(19) << endl;


    return 0;
}