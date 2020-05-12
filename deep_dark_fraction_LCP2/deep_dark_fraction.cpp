#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

class Solution 
{
public:
    vector<int> fraction(vector<int> & cont) 
    {
        if (cont.size() == 1)
        {
            vector<int> val{cont[0]};
            val.push_back(1);
            return val;
        }

        vector<int> ret;
        ret.push_back(cont[cont.size() -2] * cont[cont.size() - 1] + 1);  //作为分子
        ret.push_back(cont[cont.size() - 1]); 
    
        for (int i = cont.size() - 3; i >= 0; --i)
        {
            int tmp = ret[0];
            ret[0] = cont[i] * ret[0] + ret[1];
            ret[1] = tmp;
        }
    
        return ret;
    }
};

int main(void)
{
    vector<int> val{0, 0, 3};
    Solution so;
    vector<int> ret = so.fraction(val);
    for (auto elem : ret)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}