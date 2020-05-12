#include <iostream>
#include <string>

using namespace std;

//暴力破解，直接遍历整个字符串数组，然后找出最长回文子串
// class Solution 
// {
// public:
//     string longestPalindrome(string s) 
//     {
//         if (s.size() <= 1)
//             return s;
        
//         string max_str;
//         max_str.push_back(s[0]);
//         string cur_str;
//         for (int i = 0; i < s.size(); i++)
//         {
//             cur_str.push_back(s[i]);
//             //cout << cur_str << endl;
//             for (int j = i + 1; j < s.size(); j++)
//             {
//                 cur_str.push_back(s[j]);
//                 if (judge_palindrome(cur_str))
//                 {
                    
//                     if (cur_str.size() > max_str.size())
//                     {
//                         max_str = cur_str;
//                     }
//                 } 
//             }
//             cur_str.clear();
//         }
//         return max_str;
//     }

// private:
//     //判断一个字符串是不是回文字符串
//     bool judge_palindrome(string str)
//     {
//         int i;
//         for (i = 0; i < str.size() / 2 && str[i] == str[str.size() - 1 - i]; i++)
//             ;

//         if (i == str.size() / 2)
//             return true;
//         return false;
//     }
// };

// //中心扩散法，该方法需要注意的一个地方就是当满足条件的子串的字母个数是一个偶数时，这时应该和奇数分开来讨论
// class Solution
// {
// public:
//     string longestPalindrome(string s)
//     {
//         if (s.size() <= 1)
//             return s;

//         string max_str, cur_str;
//         max_str.push_back(s[0]);
//         for (int i = 0; i < s.size() - 1; i++)
//         {
//             // int k = i + 1;
//             // if (s[i] == s[i + 1])
//             // {
//             //     k++;
//             //     max_str = s.substr(i, 2);
//             // }
                
//             for (int j = i - 1, k = i + 1; j >= 0 && k < s.size(); j--, k++)
//             {
//                 cur_str = s.substr(j, k - j + 1);
//                 cout << "i: " << i << endl;
//                 if (judge_palindrome(cur_str))    //判断一个字符串是不是回文串
//                 {
//                     if (cur_str.size() > max_str.size())
//                         max_str = cur_str;
//                     //cout << "-----------\n";
//                 }
//                 else if (s[i] == s[i + 1])
//                 {
//                     cout << i << endl;
//                     k++;
//                     cur_str = s.substr(j, k - j + 1);
//                     if (judge_palindrome(cur_str))
//                         if (cur_str.size() > max_str.size())
//                             max_str = cur_str;
//                 }
//             }
//             cur_str.clear();
//         }
//         return max_str;
//     }
// private:
//     bool judge_palindrome(string str)
//     {
//         int i;
//         for (i = 0; i < str.size() / 2 && str[i] == str[str.size() - 1 - i]; ++i)
//             ;

//         if (i == str.size() / 2)
//             return true;
//         return false;
//     }
// };

//中心扩散法，需要考虑回文中字母个数奇偶问题
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() <= 1)
            return s;
        int begin = 0, end = 0;
        int length = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int length1 = expand_around_center(s, i, i);
            int length2 = expand_around_center(s, i, i + 1);
            length = length1 > length2 ? length1 : length2;
            if (length > end - begin + 1)
            {
                begin = i - (length - 1) / 2;
                end = i + length / 2;
            }
        }
        
        return s.substr(begin, end - begin + 1);
    }
private:
    //中心扩散
    int expand_around_center(string str, int left, int right)
    {
        while (left >= 0 && right < str.size() && str[left] == str[right])
        {
            left--;
            right++;
        }
        return right - left - 1;
    }
};

//动态规划
class Solution 
{
public:
    string longestPalindrome(string s) 
    {
        int len = s.size();
        if (len == 0 || len == 1)
            return s;
        int start = 0;//回文串起始位置
        int max = 1;//回文串最大长度
        vector<vector<int>>  dp(len,vector<int>(len));//定义二维动态数组
        for (int i = 0; i < len; i++)//初始化状态
        {
            dp[i][i] = 1;
            if (i<len-1&&s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                max=2;
                start=i;
            }
        }
        for (int l = 3; l <= len; l++)//l表示检索的子串长度，等于3表示先检索长度为3的子串
        {
            for (int i = 0; i + l - 1 < len; i++)
            {
                int j=l+i-1;//终止字符位置
                if (s[i] == s[j] && dp[i+1][j-1] == 1)//状态转移
                {
                    dp[i][j] = 1;
                    start = i;
                    max = l;
                }
            }
        }
        return s.substr(start,max);//获取最长回文子串
    }
};


int main(void)
{
    Solution so;
    string str{"abb"};
    cout << so.longestPalindrome(str) << endl;

    return 0;
}