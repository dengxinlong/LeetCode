#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution 
{
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        int ret = 0;
        for (int i = 0; i < s.size() && i < t.size(); ++i)
        {
            int count = 0;
            for (int j = i; j < s.size() && j < t.size(); j++)
            {

                count += calcu(s[j], t[j]);
                if (count > maxCost)
                    break;
                else
                    ret = ret > j - i + 1 ? ret : j - i + 1;
                
            }
        }
        
        return ret;
            
    }
private:
    int calcu(char ch, char ch2)
    {
        return (ch - ch2 > 0 ? ch - ch2 : ch2 - ch);
    }
};
int main(void)
{
    string s = "abcd";
    string t = "cdef";
    Solution so;
    cout << so.equalSubstring(s, t, 3) << endl;


    return 0;
}