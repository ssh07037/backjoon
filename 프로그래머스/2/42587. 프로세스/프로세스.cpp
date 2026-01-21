#include <string>
#include<queue>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    
    queue<int>indexs;
    vector<int>sort;
    for(int i=0; i<priorities.size(); i++)
    {
        indexs.push(i);
    }
    
    //0 1 2 3
    
    while(!indexs.empty())
    {
        int tempindex = indexs.front();
        indexs.pop();
        
        int max = 0;
        for(int i=0; i<priorities.size(); i++)
        {
            if(priorities[i] > max)
            {
                max = priorities[i];
            }
        }
       // cout << max << " max값 " << endl;
        //해당 prioritie가 최대값인지 계산
        if(priorities[tempindex] >= max)
        {
            sort.push_back(tempindex);
            priorities[tempindex] = -1;
        }
        else
        {
            indexs.push(tempindex);
        }
        
    }
    for (int i = 0; i < sort.size(); i++)
    {
       if(sort[i] == location)
       {
           answer = i+1;
       }
    }
    return answer;
}