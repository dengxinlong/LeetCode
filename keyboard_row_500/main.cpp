#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution 
{
public:
    vector<string> findWords(vector<string> & words) 
    {
        unordered_map<char, int> hash_map;
        vector<string> index{"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int i = 1;
        for (auto word : index)     //建立键盘中每个字符的位置，采用hash_map来存储
        {
            for (auto ch : word)
            {
                hash_map[ch] = i;
            }
            i++;
        }

        // for (auto elem : hash_map)
        // {
        //     cout << elem.first << ": " << elem.second << endl;
        // }
        int cur = 0; 
        vector<string> rets;
        for (auto word : words)
        {
            int j = 0;
            for (j = 0; j < word.size(); j++)
            {
                
                auto iter = hash_map.find(tolower(word[j]));
                if ( j == 0 )
                {
                    cur = iter->second;
                    continue;
                }
                    
                if (iter->second != cur)
                    break;
            }
            if (j == word.size())
                rets.push_back(word);
        }
        
        return rets;
    }
};

int main(void)
{
    Solution so;
    vector<string> words{"Hello", "Alaska", "Dad", "Peace"};
    vector<string> rets = so.findWords(words);
    
    for (auto word : rets)
        cout << word << endl;
    so.findWords(words);

    return 0;
}