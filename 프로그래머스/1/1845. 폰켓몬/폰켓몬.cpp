#include <vector>
#include <unordered_map>
#include<iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
     unordered_map<int,int> um;
    //포켓몬 중 n/2마리를 가져가도 좋다
    for(int i=0; i<nums.size(); i++)
    {
        auto it = um.find(nums[i]);
        if (it != um.end()) //같은것을 찾았다면
        {
            int value = it->second;
            um.erase(it);
            um[nums[i]] = value+1;
        }
        else
        {
           um[nums[i]] = 1;
        }
    }
    
    for(auto a : um)
    {
       // cout << a.first << "번 몬스터 " << a.second << " 만큼 존재함 " << endl;
    }
    //최대한 많은 포켓몬을 가지길 원함(중복도있음)
    if(um.size() <=  nums.size()/2)
    {
        answer = um.size();
    }
    else
    {
        answer= nums.size()/2;
    }
    return answer;
}