#include <string>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check[201];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<vector<int>> m(n); // 인접 리스트

    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++) 
        {
            if(computers[i][j] == 1) 
            {
                m[i].push_back(j); 
            }
        }
    }
    
    for(int i=0; i<n; i++) {
        if(check[i]) 
            continue; // 이미 방문했으면 건너뜀

        // 새로운 네트워크 발견
        answer++;
        queue<int> q;
        q.push(i);
        check[i] = true;
        
        while(!q.empty()) 
        {
            int head = q.front(); 
            q.pop();
            for(int next : m[head]) //해당 네트워크에 연결된 네트워크들 큐에 삽입(방문안한것만)
            { 
                if(!check[next]) 
                {
                    check[next] = true;
                    q.push(next);
                }
            }
        }
    }
    
    return answer;
}