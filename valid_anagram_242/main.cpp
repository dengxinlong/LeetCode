#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;
//这里需要理解题目中异位词的意思
//就是对一个单词中的字符变换顺序，新单词就是原来单词的异位词

//排序法，将两个单词进行排序，如果排序后的结果相同，则这两个单词就是异位词
// class Solution 
// {
// public:
//     bool isAnagram(string s, string t) 
//     {
//         if (s.size() != t.size())
//             return false;

//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s == t;
//     }
// };


//哈希表法
//我们知道，异位词的长度是一致的，这时候我们统计单词中每个字符出现的次数，如果两个字符串中有一个字符出现的次数不相等，就表示这两个单词不是异位词
class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        if (s.size() != t.size())
            return false;
        
        vector<int> counts;
        counts.resize(26, 0);

        for (auto elem : s)
            counts[elem - 'a']++;
        
        for (auto elem : t)
        {
            counts[elem - 'a']--;
            if (counts[elem - 'a'] < 0)
                return false;
        }

        // for (int i = 0; i < s.size(); ++i)
        // {
        //     counts[s[i] - 'a']++;
        //     coutts[t[i] - 'a']--;
        // }
        
        // for (auto elem : counts)
        //     if (elem != 0)
        //         return false;

        return true; 
    }
};

//进阶：如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
//如果字符串中包含了unicode字符，这时因为字符串中不同字符的个数是不确定的，如果用数组来存储的话，大小是没法固定的，这时要使用计数器来统计每个字符出现的次数，因为大小没办法固定
//这时可以采用hash_map来存储，支持随机访问，时间复杂度不变，但空间复杂度为O(n)，其会随着字符串中不同字符个数的增加而增加

int main(void)
{
    Solution so;
    cout << so.isAnagram("rat", "car") << endl;

    return 0;
}