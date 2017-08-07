#include <vector>
#include <stack>

#include <iostream>

using namespace std;

class TwoStacks {
public:
    vector<int> twoStacksSort(vector<int> numbers) {
        stack<int> st1;
        stack<int> st2;
        for(auto it:numbers)
            st1.push(it);

        int length = st1.size();
        int top1,top2;
        top2 = st1.top();
        st2.push(top2);
        st1.pop();

        while(!st1.empty())
        {
            top1 = st1.top();
            while(!st2.empty() && st2.top() > top1)
            {
                st1.push(st2.top());
                st2.pop();

            }
            st2.push(top1);
            while(!st1.empty() && st1.top() > top1)
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.pop();
        }
        vector<int> res;
        while(!st2.empty())
        {
            res.push_back(st2.top());
            st2.pop();
        }
        return res;
    }
};

int main()
{
    vector<int> in={1,2,3,4,5};
    TwoStacks ts;
    vector<int> res;
    res = ts.twoStacksSort(in);
    for(auto it: res)
        cout<<it<<"  ";
    cout<<endl;
    return 0;
}
