#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//题目为反转字符串中的元音字母，
//根据测试用例，但一个字母不是元音字母，而另一个是时，这时不进行交换，直到找到刚刚不是元音字母的字符为元音字母时
class Solution 
{
public:
    Solution(void)
    : _hash_index(unordered_set<char>{'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'})
    {}
    
    string reverseVowels(string s) 
    {
        for (int i = 0, j = s.size() - 1; i < j; )
        {
            if (!is_vowel(s[i]))
            {
                i++;
                continue;
            }
            if (!is_vowel(s[j]))
            {
                j--;
                continue;
            }
            // cout << "i: " << i << " " << "j: " << j << endl;
            s[i] ^= s[j];
            s[j] ^= s[i];
            s[i] ^= s[j];

            i++;
            j--;
        }

        return s;
    }

private:
    bool is_vowel(char ch)    //判断一个字母是不是元音字母
    {
        if (_hash_index.find(ch) != _hash_index.end())
            return true;
        return false;
    }
    
    unordered_set<char> _hash_index; //{'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u'};
};

int main(void)
{
    string str{"hello"};            //holle
    Solution so;
    cout << so.reverseVowels(str) << endl;


    return 0;
}