#include <iostream>
#include <vector>

using namespace std;


//暴力破解
//时间复杂度：O(N * 2), 空间复杂度：O(1)
// class Solution 
// {
// public:
//     int maxArea(vector<int>& height) 
//     {
//         int ret = 0;
//         for (int i = 0; i < height.size(); i++)
//         {
//             for (int j = i + 1; j < height.size(); j++)
//             {
//                 int cur_ret = min(height[i], height[j]) * (j - i);
//                 ret = cur_ret > ret ? cur_ret : ret;
//             }
//         }

//         return ret;
//     }
// };

//这题根据题目意思，存在两个变量：一个是长度，一个是高度
//我们可选择一个变量使得其在当前情况下最大，高度显然不合适，因为需要查找最大值，所以选择长度
//长度就是数组下标之间的距离，先使得这个值在当前情况下最大，然后一步步的得出容器的最大值
//时间复杂度：O(N), 空间复杂度：O(1)
class Solution
{
public:
    int maxArea(vector<int> & height)
    {
        int ret = 0;
        for (int i = 0, j = height.size() - 1; i < j; )
        {
            ret = max(ret, min(height[i], height[j]) * (j - i));

            if (height[i] > height[j])
                j--;
            else
                i++;
        }

        return ret;
    }
};

//动态规划
//在暴力破解法中，我们进行双层循环来得出答案，但是在循环中，我们可以利用一层遍历得出双层循环需要的计算结果
// class Solution
// {
// public: 
//     int maxArea(vector<int> & height)
//     {

//     }
// }

int main(void)
{
    vector<int> height{1,8,6,2,5,4,8,3,7};
    Solution so;
    cout << so.maxArea(height) << endl;

    return 0;
}