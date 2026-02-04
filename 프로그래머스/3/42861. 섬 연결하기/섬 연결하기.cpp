#include <vector>
#include <climits>
using namespace std;

bool visited[100];
int min_cost[100];

int solution(int n, vector<vector<int>> costs) {
    // 그래프 구성
    vector<vector<pair<int,int>>> graph(n);
    for (auto& c : costs) {
        graph[c[0]].push_back({c[1], c[2]}); //0 : 1,1  2,2 ...
                                             //1 : 0,1 2,5 .... 각 지점에서 갈 수 있는 곳과 가격 알아냄
        graph[c[1]].push_back({c[0], c[2]});
    }

    // 초기화
    for (int i = 0; i < n; i++)
        min_cost[i] = INT_MAX;

    min_cost[0] = 0;  // 0번 섬에서 시작
    int answer = 0;

    for (int i = 0; i < n; i++) {
        int cur = -1;
        int cost = INT_MAX;

        // 아직 방문 안 한 섬 중 최소 비용 섬 선택
        for (int j = 0; j < n; j++) {
            if (!visited[j] && min_cost[j] < cost) { //방문하지않았고 가격이 싸다면
                cost = min_cost[j];
                cur = j;
            } //0->1로 비용 1
        }

        visited[cur] = true;
        answer += cost;

        // 연결된 섬 비용 갱신
        for (auto& next : graph[cur]) {
            int nextNode = next.first;
            int nextCost = next.second;
            if (!visited[nextNode] && min_cost[nextNode] > nextCost) {
                min_cost[nextNode] = nextCost;
            }
        }
    }

    return answer;
}
