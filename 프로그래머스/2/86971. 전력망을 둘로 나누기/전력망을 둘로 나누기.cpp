#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<int>> adj;
bool visited[101];

// DFS로 서브트리 크기 계산
int dfs(int cur) {
    visited[cur] = true;
    int cnt = 1;

    for (int next : adj[cur]) { //1번과 연결된것 돔 //1+1+....
        if (!visited[next]) {
            cnt += dfs(next);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;

    for (int i = 0; i < wires.size(); i++) {
        // 그래프 초기화
        adj.assign(n + 1, vector<int>()); //초기화

        // i번째 전선을 제외하고 그래프 구성
        for (int j = 0; j < wires.size(); j++) {
            if (i == j) continue;
            int a = wires[j][0];
            int b = wires[j][1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //wires에서 노드가 없는것을 가정해서 2중 vector 쌩성

        // 방문 배열 초기화
        fill(visited, visited + 101, false);

        // 한쪽 서브트리 크기 계산 (트리기떄문에 루트부터 차례대로해서 서브트리를 계산)
        int cnt = dfs(1);
        cout << cnt << endl;
        // 두 전력망 차이 계산
        int diff = abs(cnt - (n - cnt)); //나머지 서브트리와의 차이 계산 , 비교
        answer = min(answer, diff);
    }

    return answer;
}
