#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) {
        if (a[1] != b[1]) 
            return a[1] > b[1]; // 소요시간 짧은 순
        return a[0] > b[0];                  // 요청시각 빠른 순
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end()); // 요청 시각 기준 정렬

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    int time = 0;
    int index = 0;
    int total = 0;
    int n = jobs.size();

    while (index < n || !pq.empty()) {
        while (index < n && jobs[index][0] <= time) {
            pq.push(jobs[index]);
            index++;
            //현재 시간보다 적은 시작시간을 전부 pq에 넣음
        }

        if (pq.empty()) {
            // 아직 도착한 작업이 없으면 시간 점프
            time = jobs[index][0];
        } else {
            auto cur = pq.top();
            pq.pop();

            time += cur[1];
            total += time - cur[0]; // 반환 시간
        }
    }

    return total / n;
}
