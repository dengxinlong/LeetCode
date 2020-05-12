#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//说明：这题本质上可以看成是一道统计字符串s中每个字符出现的次数
class Solution 
{
public:
    int longestPalindrome(string s) 
    {
        unordered_map<char, int> counts;
        for (auto elem : s)
            counts[elem]++;
        
        int ret = 0;
        for (auto elem : counts)
        {
           ret += elem.second / 2 * 2;
        //    if (elem.second % 2 && ret % 2 == 0)
        //         ret++;
        }

        if (ret < s.size())     //这里主要是为了代替上面的 if 判断，因为上面的if判断每次循环都需要执行一次，这里就在最后执行一次即可，减少了不必要的判断
            ret++;
        return ret;
    }
};

int main(void)
{
    string str("bananas");
    Solution so;
    cout << so.longestPalindrome(str) << endl;



    return 0;
}