#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    int romanToInt(string s) 
    {
        // //建立索引
        // int ret = 0;
        // unordered_map<char, int> index_numbers{make_pair('I', 1), make_pair('V', 5), 
        //                                        make_pair('X', 10), make_pair('L', 50), 
        //                                        make_pair('C', 100), make_pair('D', 500), 
        //                                        make_pair('M', 1000)};
        // int i = 0;
        // while ( i < s.size() - 1 )
        // {
        //     if (index_numbers[s[i]] < index_numbers[s[i + 1]])
        //         ret += index_numbers[s[i + 1]] - index_numbers[s[i++]];
        //     else
        //         ret += index_numbers[s[i]];
        //     i++;
        // }
        // //可能需要处理最后一个字符
        // if ( i == s.size() - 1)
        // {
        //     ret += index_numbers.find(s[i])->second;
        // }

        //或者写下面的写法
        // int ret = 0;
        // unordered_map<char, int> index_numbers{make_pair('I', 1), make_pair('V', 5), 
        //                                        make_pair('X', 10), make_pair('L', 50), 
        //                                        make_pair('C', 100), make_pair('D', 500), 
        //                                        make_pair('M', 1000)};
        // for (int i = 0; i < s.size() - 1; ++i)
        // {
        //     if (index_numbers[s[i]] < index_numbers[s[i + 1]])
        //         ret -= index_numbers[s[i]];
        //     else
        //         ret += index_numbers[s[i]];
        // }
        // ret += index_numbers[s[s.size() - 1]];

        //或者写下面的写法
        int ret = 0;
        unordered_map<string, int> index_numbers{make_pair("I", 1), make_pair("V", 5), 
                                               make_pair("X", 10), make_pair("L", 50), 
                                               make_pair("C", 100), make_pair("D", 500), 
                                               make_pair("M", 1000), make_pair("IV", 4),
                                               make_pair("IX", 9), make_pair("XL", 40),
                                               make_pair("XC", 90), make_pair("CD", 400),
                                               make_pair("CM", 900)};
        for (int i = 0; i < s.size(); ++i)
        {
            if (index_numbers[s.substr(i, 2)])
            {
                ret += index_numbers[s.substr(i, 2)];
                ++i;
            }
            else
                ret += index_numbers[s.substr(i, 1)];
        }

        return ret;
    }
};
//说明：上面三种写法在本质上都是相同的，只是在遍历字符串的时候，第1种写法进行了if判断比较后面的字符，而第二种写法没有进行判断，利用了在遍历过程中发现的规律
//      第三种写法每次先取出当前遍历到到字符的2字符的子串，判断是否在hash_map存在，如果存在则直接相加，同时最终使得i+2，如果不存在，只加一个字符对应的值
//      相比较而言，第二种写法更加巧妙一些，利用了其转换规律

int main(void)
{
    Solution so;
    string str{"III"};
    cout << so.romanToInt(str) << endl;


    return 0;
}