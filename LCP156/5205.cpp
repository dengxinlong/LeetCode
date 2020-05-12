#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    bool uniqueOccurrences(vector<int> & arr) 
    {
        if (arr.size() == 1)
            return true;
        sort(arr.begin(), arr.end());           //先排序，时间复杂度为O(nlogn)
        for (auto elem : arr)
            cout << elem << " ";
        cout << endl;
        vector<int> counts;
        int count = 1;
        for (int i = 0; i < arr.size() - 1; ++i)
        {
            if (arr[i] == arr[i + 1])
            {
                count++;
            }
            else
            {
                counts.push_back(count);
                count = 1;
            }
        }
        counts.push_back(count);
        for (auto elem : counts)
            cout << elem << " ";
        cout << endl;

        sort(counts.begin(), counts.end());
        for (int i = 0; i < counts.size() - 1; ++i)
        {
            if (counts[i] == counts[i + 1])
                return false;
        }
        return true;
    }
};

int main(void)
{
    vector<int> vec{1,2};
    Solution so;
    cout << so.uniqueOccurrences(vec) << endl;


    return 0;
}