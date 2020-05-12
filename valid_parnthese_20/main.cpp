#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// class Solution 
// {
// public:
//     bool isValid(string s) 
//     {
//         for (auto ch : s)
//         {
//             if (ch == ' ')
//                 continue;
//             if (ch == '(' || ch == '{' || ch == '[')
//             {
//                 _stack.push_back(ch);
//                 continue;
//             }
//             else if (ch == ']')
//             {
//                 if (!_stack.size() || _stack.back() != '[')
//                     return false;
                
//             }
//             else if (ch == ')')
//             {
//                 //cout << _stack.back() << endl;
//                 if (!_stack.size() || _stack.back() != '(')
//                     return false;
//             }
//             else if (ch == '}')
//             {
//                 //cout << _stack.back() << endl;
//                 if (!_stack.size() || _stack.back() != '{')
//                     return false;
//             }

//             _stack.pop_back();
//         }

//         return !_stack.size();
//     }

// private:
//     vector<char> _stack;
// };

//同样的思路，不过利用hash_map来简化if else操作
class Solution 
{
public:
    bool isValid(string s) 
    {
        unordered_map<char, char> hash_map{{')', '('}, {'}', '{'}, {']', '['}};
        for (auto ch : s)
        {
            if (ch == ' ')
                continue;
            
            auto iter = hash_map.find(ch);
            if ( iter != hash_map.end())
            {
                if (!_stack.size() || iter->second != _stack.back())
                    return false;
                _stack.pop_back();
            }
            else
                _stack.push_back(ch);
        }

        return !_stack.size();
    }

private:
    vector<char> _stack;
};


int main(void)
{
    Solution so;
    string str("){");
    cout << so.isValid(str) << endl;


    return 0;
}