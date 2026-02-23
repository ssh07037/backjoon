#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
bool check[20000];
int depth[20000];

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    //1번 노드에서 가장 멀리 떨어진 노드의 갯수 
    unordered_map<int,vector<int>>m;
    for(auto a : edge)
    {
        m[a[0]].push_back(a[1]);
        m[a[1]].push_back(a[0]);
    }
    
    queue<int>q;
    q.push(1);
    check[1] = true;
    depth[1] = 0;
    int max = 0;
    while(!q.empty())
    {  
        int temp = q.front();
        q.pop();
        
        for(auto a : m[temp]) //넓이우선탐색
        {
            if(check[a] == false) //간곳이 아니라면 1과 연결된 2,3을 추가
            {
                check[a] = true;
                q.push(a);
                depth[a] = depth[temp] + 1;
                //cout << a << "노드의 깊이는 " << depth[a] << "입니다" << endl;
                if(max < depth[a])
                {
                    max = depth[a];
                    answer = 1;
                }
                else if(max == depth[a])
                {
                    answer++;
                }
            }
        }
    }
    
    
    
    return answer;
}