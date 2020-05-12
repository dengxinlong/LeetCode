#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

//排序法
//时间复杂度为O(NlogN)
// class Solution 
// {
// public:
//     char findTheDifference(string s, string t) 
//     {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         //cout << s << " " << t << endl;
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s[i] != t[i])
//                 return t[i];
//         }

//         return t[t.size() - 1];
//     }
// };

// //hash_table
// class Solution
// {
// public:
//     char findTheDifference(string s, string t)
//     {
//         unordered_map<char, int> index;
//         for (int i = 0; i < t.size(); i++)
//         {
//             index[t[i]]++;
//             index[s[i]]--;
//         }
            
//         // for (auto elem : s)
//         //     index[elem]--;
//         for (auto elem : index)
//             if (elem.second == 1)
//                 return elem.first;
//         return ' ';
//     }
// };


//位运算
// class Solution
// {
// public:
//     char findTheDifference(string s, string t)
//     {
//         char ret = t[t.size() - 1];
//         for (int i = 0; i < s.size(); ++i)
//             ret = s[i] ^ ret ^ t[i];
//         return ret;
//     }
// };

//ASCI码之和
class Solution
{
public:
    char findTheDifference(string s, string t)
    {
        int ret = t[t.size() - 1];
        for (int i = 0; i < s.size(); ++i)
        {
            ret += t[i];
            ret -= s[i];
        }

        return (char)ret;
    }
};


int main(void)
{
    Solution so;
    string str1 = "abcd", str2 = "abcde";
    cout << so.findTheDifference(str1, str2) << endl;


    return 0;
}