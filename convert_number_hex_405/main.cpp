#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

//将十进制数转换为十六进制
//先考虑正数，然后考虑负数，因为负数采用补码的形式
// class Solution 
// {
// public:
//     string toHex(int num) 
//     {
        // unordered_map<int, char> index_map{{10, 'A'}, {11, 'B'}, {12, 'C'}, 
        //                                     {13, 'D'}, {14, 'E'}, {15, 'F'}};
        // long value = num;
        // if (value < 0)
        //     value = numeric_limits<unsigned int>::max() + value + 1;
        // cout << "value: " << value << endl;
        // string ret;
        // for (; value; value /= 16)
        // {
        //     if (index_map[value % 16] > 0)
        //         ret.insert(ret.begin(), index_map[value % 16]);
        //     else
        //         ret = std::to_string(value % 16) + ret;
        // }
        // return ret;
        /*或采用下面的写法
        string ret, hex("0123456789abcdef");
        //不管输入的数是正数还是负数，全部转换为正数
        unsigned int value = num;
        while (value)
        {
            ret = hex[value % 16] + ret;
            value /= 16;
        }

        return ret;
//     }
// };

//leetcode中网友的解法，根据位运算进行解决，非常巧妙
class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
            return "0";
        string hex("0123456789abcdef"), ret = "";

        while (num && ret.size() < 8)
        {
            ret = hex[num & 0xf] + ret;
            num >>= 4;
        }

        return ret;
    }

};

int main(void)
{
    int num = -1;
    Solution so;
    cout << so.toHex(num) << endl;


    return 0;
}