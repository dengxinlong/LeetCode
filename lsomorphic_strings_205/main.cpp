#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;


//这题的关键就是
//两个相同的字符映射到不同的字符
//两个不同的字符映射到相同的字符，其实本质上就是两个相同的字符映射到不同的字符上面，当发生这种情况时，两个字符串就不是同构字符串
// class Solution 
// {
// public:
//     bool isIsomorphic(string s, string t) 
//     {
//         for (int i = 0; i < s.size(); i++)
//         {
//             if (s.find(s[i]) != t.find(t[i]))
//                 return false;
//         }
//         return true;
//     }
// };

//使用Hash_map来解决
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        return is_isomorphic(s, t) && is_isomorphic(t, s);
    }
private:
    bool is_isomorphic(string s, string t)
    {
        unordered_map<char, char> index_map;
        for (int i = 0; i < s.size(); ++i)
        {
            auto iter = index_map.find(s[i]);
            if (iter == index_map.end())   //这里因为c++无法根据值来查找
            {
                index_map[s[i]] = t[i];
            }
            else
            {
                if (iter->second != t[i])
                    return false;
            }
        }
    }
};

int main(void)
{
    Solution so;
    cout << so.isIsomorphic("eab", "cgg") << endl;

    return 0;
}