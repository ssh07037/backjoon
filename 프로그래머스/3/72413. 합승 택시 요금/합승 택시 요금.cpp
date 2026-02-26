#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
void dijkstra(int start,const vector<vector<pair<int,int>>>& v,int d[])
{
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> q; //제일 비용이 적은것부터 우선순위큐
    q.push({0, start});
    d[start] = 0;

    while (!q.empty())
    {
        auto [cost, cur] = q.top();
        q.pop();

        if (cost > d[cur]) continue; //넓이우선에서 이미 지나갔는데 비용이 크면 스킵

        for (auto [next, fee] : v[cur])
        {
            if (d[cur] + fee < d[next])
            {
                d[next] = d[cur] + fee;
                q.push({d[next], next});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<pair<int,int>>>v(n+1);
    for(auto a : fares)
    {
        v[a[0]].push_back(make_pair(a[1],a[2]));
        v[a[1]].push_back(make_pair(a[0],a[2]));
    }
    
    /*for(auto a : v)
    {
        for(auto b : a)
            cout << " 다음 위치:" << b.first <<  " 비용:" << b.second << endl;
        cout << endl;
    }*/
    int d1[n+1];
    int d2[n+1];
    int d3[n+1];
    for (int i = 0; i < n+1; i++)
    {
        d1[i] = INT_MAX;
        d2[i] = INT_MAX;
        d3[i] = INT_MAX;
    }
    dijkstra(s,v,d1);
    dijkstra(a,v,d2);
    dijkstra(b,v,d3);
    
    answer = INT_MAX;

    for (int i = 1; i <= n; i++) //i번째까지 합승했을떄의 값 추출해서 가장 최소(가장많이 합승하면서도 비용이적은것 탐색)
    {
        answer = min(answer, d1[i] + d2[i] + d3[i]);
    }
    return answer;
}