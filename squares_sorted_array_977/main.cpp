#include <iostream>
#include <vector>

using namespace std;

//方法一：先计算数组中每个数的平方，然后再对该数组进行排序
// class Solution 
// {
// public:
//     vector<int> sortedSquares(vector<int> & A) 
//     {
//         vector<int> ret;
//         for (auto elem : A)
//         {
//             ret.push_back(elem * elem);
//         }
        
//         sort(ret.begin(), ret.end());
//         return ret;
//     }
// };

//方法二：双指针，先找到数组当中元素值符号不一致的元素，如果没有，则可以直接将元素的值的平方降序或者升序插入到ret结果数组当中
//如果有，则其中一个指针指向0元素，另一个指向旁边的元素，哪个更小则插入到ret中，直到遍历结束
class Solution 
{
public:
    vector<int> sortedSquares(vector<int> & A) 
    { 
        vector<int> ret;
        int priot = 0;
        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i - 1] < 0 && A[i] >= 0)
            {
                priot = i;
                break;
            }
        }

        int i= priot, j = priot - 1;
        while ( i < A.size() && j >= 0 )
        {
            if (A[i] * A[i] <= A[j] * A[j])
                ret.push_back(A[i] * A[i++]);
            else
                ret.push_back(A[j] * A[j--]);
        }
  
        while (i < A.size())
            ret.push_back(A[i] * A[i++]);
        while (j >= 0)
            ret.push_back(A[j] * A[j--]);
        
        return ret;
    }
};

int main(void)
{
    Solution so;
    vector<int> nums{-4,-1,0,3,10};
    vector<int> ret = so.sortedSquares(nums);
    
    for (auto elem : ret)
        cout << elem << " ";
    cout << endl;



    return 0;
}