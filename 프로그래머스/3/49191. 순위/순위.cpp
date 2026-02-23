#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int dfs(int n,int node , const vector<vector<int>>& graph)
{
    int count = 0;
    vector<bool> check(n + 1, false);
    queue<int>q;
    check[node] = true;
    q.push(node);
    while(!q.empty())
    {
        int temp = q.front(); //1
        q.pop();
        for(auto a : graph[temp])
        {
            if(check[a] == false)
            {
                q.push(a);
                count++;
                check[a] = true;
            }
        }
    }
    return count;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>>loses(n+1);
    vector<vector<int>>wins(n+1);
    
    for(auto a : results)
    {
        loses[a[1]].push_back(a[0]);
        wins[a[0]].push_back(a[1]);
    }
    
    for(int i=1; i<=n; i++)
    {
        int lose_count = dfs(n,i,loses);
        int win_count = dfs(n,i,wins);
        //cout << lose_count << " " << win_count << endl;
        if(lose_count + win_count + 1== n)
            answer++;
    }
    return answer;
}