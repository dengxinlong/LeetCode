#include <iostream>
#include <string>
#include <stack>

using namespace std;


//利用栈的思想解决
// class Solution 
// {
// public:
//     bool backspaceCompare(string S, string T) 
//     {
//         int k = 0, i = -1, j = 0;
//         fpr (int k = 0; k < S.size(); k++)
//         {
//             if (S[k] != '#')
//             {
//                 i = k;
//                 break;
//             }
//         }

//         while (k < S.size())
//         {
//             if (S[k] != '#')
//             {
//                 i++;
//                 j++:
//             }
            
//         }
//     }
// };


//利用栈来解决
class Solution 
{
public:
    bool backspaceCompare(string S, string T) 
    {
        stack<char> stack_S, stack_T;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] != '#')
            {
                stack_S.push(S[i]);
            }
            else if (stack_S.size())
            {
                stack_S.pop();
            }
        }  
                
        for (int i = 0; i < T.size(); i++)
        {
            if (T[i] != '#')
            {
                stack_T.push(T[i]);
            }
            else if (stack_T.size())
            {
                stack_T.pop();
            }
        }

        // if (stack_T.size() != stack_S.size())
        //     return false;
        // while (stack_T.size())
        // {
        //     if (stack_T.top() == stack_S.top())
        //     {
        //         stack_T.pop();
        //         stack_S.pop();
        //     }
        //     else
        //         return false;
        // }
        if (stack_T == stack_S)
            return true;
        else
            return false;
        
        return true;
    }
};

int main(void)
{
    Solution so;
    string S{"xywrrmp"}, T{"xywrrmu#p"};
    cout << so.backspaceCompare(S, T) << endl;


    return 0;
}