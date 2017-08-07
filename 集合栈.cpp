
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SetOfStacks {
public:
    vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
        // write code here
        vector<vector<int>> res;
        vector<int> tmp;
        for(int i=0; i<ope.size();i++)
        {
            if(ope[i][0] == 1)
            {
                if(tmp.size() == size)
                {
                    res.push_back(tmp);
                    tmp.clear();
                    tmp.push_back(ope[i][1]);
                }
                else
                    tmp.push_back(ope[i][1]);
            }
            if(ope[i][0] == 2)
            {
                if(tmp.size() != 0)
                {
                    tmp.pop_back();
                }
                else if(res.size() != 0)
                {
                    tmp = res[res.size()-1];
                    tmp.pop_back();
                    res.pop_back();
                }
            }
        }
        if(tmp.size()!=0)
            res.push_back(tmp);
        return res;
    }
};
