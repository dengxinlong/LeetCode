#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

//暴力解法
// class Solution
// {
// public:


// private:

// };

//排序法，该题的本质就是找出数组中不同元素的个数count，然后返回size / 2, count的较小者
// class Solution
// {
// public:
//     int distributeCandies(std::vector<int>& candies) {
//         if (!candies.size()) return 0;
//         std::sort(candies.begin(), candies.end());
//         int count = 1;
//         for (int i = 0; i < candies.size() - 1; i++) {
//             if (candies[i] < candies[i + 1]) {
//                 std::cout << "good.\n";
//                 count++;
//             }
//         }
//         return count < candies.size() / 2 ? count : candies.size() / 2;
//     }
// };

//本题实质上就是求解数组中元素的种类个数，这时可以利用set的性质，相同元素不会进入该set中，set的大小就是元素的种类个数
class Solution
{
public:
    int distributeCandies(std::vector<int>& candies)
    {
        std::unordered_set<int> hashSet;
        for (int i = 0; i < candies.size(); i++) {
            hashSet.insert(candies[i]);
        }
        return candies.size() / 2 < hashSet.size() ? candies.size() / 2 : hashSet.size();
    }
private:

};

int main(void)
{
    Solution so;
    std::vector<int> nums{1, 1, 2, 2, 3, 3};
    std::cout << so.distributeCandies(nums) << std::endl;

    return 0;
}