#include <string>
#include <vector>
#include <iostream>
using namespace std;
int dc[4] = {10,20,30,40};
int max_sub = 0;
int max_value = 0;
void dfs(const vector<int>& emoticons, int index, vector<pair<int,int>>& stack,vector<vector<int>>& users)
{
    if (index == emoticons.size())
    {
        int sub = 0;
        int sum_value = 0;
        for(auto a : users)
        {
            int value = 0;
            for(auto b : stack)
            {
                if(a[0] <= b.first) //할인율이 더 높다면
                {
                    value += b.second; //해당 이모티콘 구매
                }
            }
            if(value >= a[1]) //유저의 예상가격보다 더 많이 산다면
            {
                sub++;
            }
            else
            {
                sum_value += value;
            }
        }
        
        if (sub > max_sub ||
        (sub == max_sub && sum_value > max_value))
        {
            max_sub = sub;
            max_value = sum_value;
        }
        
        return;
    }

    for (int j = 0; j < 4; j++)
    {
        int temp = emoticons[index] * (100 - dc[j]) / 100;
        stack.push_back(make_pair(dc[j],temp));

        dfs(emoticons, index + 1, stack,users);

        stack.pop_back();
    }
}
vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    //이모티콘 플러스 가입자를 늘린다
    //이모티콘 판매액을 늘린다
    //사람들은 특정 할인율 이상이 아니면 구매하지 않는다
    
    //만원이상 구매하면 플러스 가입함
    vector<pair<int,int>>stack;
    dfs(emoticons,0,stack,users);
    
    cout << max_sub << " " << max_value << endl;
    answer.push_back(max_sub);
    answer.push_back(max_value);
    return answer;
}