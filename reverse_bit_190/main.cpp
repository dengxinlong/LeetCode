#include <iostream>
#include <string>
#include <vector>

using namespace std;


//解法：
//    这题是关于二进制交换问题，就是将一个数的二进制数表示法中进行逆置
//    很显然，这题是想考察位运算，我们先把输入数看成一个二进制数，不用真实的去转换，其在内存中就是一个二进制数，用何种方式表示不重要，反正其属性是一致的
//    先定义一个32位无符号整数ans，用来存储结果，其实就是要将输入数逆置，那么我们可以一次取出n的每一位，然后放置到ans中，但是，怎么放置呢，这是一个问题，
//    其实很好解决，放置前先将ans左移一位，然后直接加到ans上面就行了；同时，因为是逆置，那么就需要将在n中取出的每一位移位到适当的位置，其实，在我们移位ans
//    时，每次需要把n中取出的一位加到ans中时，已经将ans移动了一位，经过32次循环，每个位都在适当的位置
class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans = 0; 
        for (int i = 0; i < 32; ++i)
        {
            ans <<= 1;
            ans += n & 1;
            n >>= 1;
        }

        return ans;
    }
};

int main(void)
{



    return 0;
}