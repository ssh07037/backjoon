#include <string>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int min_cost[100];
bool check[100];
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<vector<pair<int,int>>> graph(n);
    for (auto& a : costs) 
    {
        graph[a[0]].push_back(make_pair(a[1],a[2]));
        graph[a[1]].push_back(make_pair(a[0],a[2]));
    }
    for (int i = 0; i < n; i++)
    {
        min_cost[i] = INT_MAX;
    }
    min_cost[0] = 0;
    
    for(int i=0; i<n; i++)
    {
        int min = INT_MAX;
        int index = 0;
        for(int j=0; j<n; j++) //최소값 찾기
        {
            if(min > min_cost[j] && check[j] == false)
            {
                min = min_cost[j];
                //cout << min << endl;
                index = j;
            }
        }
        check[index] = true;
        
        for(auto a : graph[index]) //갱신
        {
            int next = a.first;
            cout << next << endl;
            int next_cost = a.second;
            if(min_cost[next] > next_cost)
            {
                min_cost[next] = next_cost;
            }
        }
        answer += min;
        
    }
    return answer;
}