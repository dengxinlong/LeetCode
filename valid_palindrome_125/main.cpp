#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;



//直接采用双指针法，一个指针指向字符串的头部，一个指向字符串的尾部
// class Solution 
// {
// public:
//     bool isPalindrome(string s) 
//     {
//         if (s.size() == 0)
//             return true;
        
//         for (int i = 0, j = s.size() - 1; i < j; i++, j--)
//         {
//             while (i < j && !(s[i] <= 'z' && s[i] >= 'a' || s[i] <= 'Z' && s[i] >= 'A' || s[i] <= '9' && s[i] >= '0') || s[i] == ' ')
//                 i++;
//             while (i < j && !(s[j] <= 'z' && s[j] >= 'a' || s[j] <= 'Z' && s[j] >= 'A' || s[j] <= '9' && s[j] >= '0') || s[j] == ' ') 
//                 j--;
//            // cout << "i: " << s[i] << " " << "j: " << s[j] << endl;
//             //处理小写字母
//             s[i] = tolower(s[i]);
//             s[j] = tolower(s[j]);
//             if (i < j && s[i] != s[j])
//                 return false;
//         }

//         return true;
//     }   
// };


//算法和上面一样，只是这里使用C++提供的检测一个字符是否是标点符号的函数
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (int i = 0, j = s.size() - 1; i < j; )
        {
            if (ispunct(s[i]) || isspace(s[i]))
            {
                i++;
                continue;
            }
                
            if (ispunct(s[j]) || isspace(s[j]))
            {
                j--;
                continue;
            }
            
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }

        return true;
    }
};

int main(void)
{
    string str{"''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''''"};
    Solution so;
    cout << so.isPalindrome(str) << endl;



    return 0;
}