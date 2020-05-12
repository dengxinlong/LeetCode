#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    int game(vector<int> & guess, vector<int> & answer) 
    {
        int count = 0;
        for (int i = 0; i < guess.size(); ++i)
        {
            if (guess[i] == answer[i])
                count++;
        }
        return count;
    }
};

int main(void)
{
    vector<int> guess{2, 2, 3}, answer{3, 2, 1};
    Solution so;
    int count = so.game(guess, answer);
    cout << count << endl;

    return 0;
}