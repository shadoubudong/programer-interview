#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CatDogAsulum
{
public:
    vector<int> asylum(vector<vector<int>> ope)
    {
        queue<int> dog;
        queue<int> cat;
        vector<int> res;
        int index = 0;
        int size = ope.size();
        for(int i=0; i<size; i++)
        {
            int flag = ope[i][0];
            if(flag == 1) //有动物进入
            {
                if(ope[i][i] > 0) //狗进入
                {
                    dog.push(index++);//用于表示时间戳
                    dog.push(ope[i][1]);
                }
                else
                {
                    cat.push(index++);
                    cat.push(ope[i][1]);
                }
            }
            else //领养动物
            {
                if(ope[i][1] == 0)//第一种收养方式
                {
                    int first = 0; //代表取走的是猫或者是狗，1代表狗，-1代表猫
                    if(cat.empty()&&!dog.empty())
                    {
                        first = 1;
                    }
                    if(!cat.empty() && dog.empty())
                    {
                        first = -1;
                    }
                    if(!cat.empty() && !dog.empty())
                    {
                        if(dog.front() > cat.front())
                            first = -1;
                        else
                            first = 1;
                    }
                    if(first == 1) //取走狗
                    {
                        dog.pop();//弹出时间戳
                        res.push_back(dog.front());//获取的动物
                        dog.pop();//弹出已经被获取的动物
                    }
                    if(first == -1)
                    {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    }
                }
                else //第二种收养方式
                {
                    if(ope[i][1] == 1 && !dog.empty())
                    {
                        dog.pop();
                        res.push_back(dog.front());
                        dog.pop();
                    }
                    if(ope[i][1] == -1 && !cat.empty())
                    {
                        cat.pop();
                        res.push_back(cat.front());
                        cat.pop();
                    }
                }
            }
        }
        return res;
    }
};
