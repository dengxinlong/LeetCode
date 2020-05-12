#include <iostream>
#include <string>
#include <vector>

using namespace std;


//暴力破解, 时间复杂度为O(N)
// class Solution 
// {
// public:
//     bool isSubsequence(string s, string t) 
//     {
//         if (s.size() && !t.size())
//             return false;
//         else if (!s.size() || !t.size())
//             return true;
        
//         int k = 0, cnt = 0;
//         for (int i = 0; i < s.size(); ++i)
//         {
//             for (int j = k; j < t.size(); ++j)          //因为s要为t的子序列，顺序必须要一致，即字符之间的相对位置不能改变
//             {
//                 if (s[i] == t[j])
//                 {
//                     k = j + 1;
//                     cnt++;
//                     break;
//                 }
//                 if (j == t.size() - 1)
//                     return false; 
//             }
//         }
       
//         return cnt == s.size();
//     }
// };

//双指针法
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int i, j;
        for (i = 0, j = 0; i < s.size() && j < t.size(); ++j)
        {
            if (s[i] == t[j])
                i++;
        }

        return i == s.size();
    }
};

int main(void)
{
    Solution so;
    string str1{"twn"}, str2{"xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxtxxxxxxxxxxxxxxxxxxxxwxxxxxxxxxxxxxxxxxxxxxxxxxn"};
    cout << so.isSubsequence(str1, str2) << endl;

    return 0;
}