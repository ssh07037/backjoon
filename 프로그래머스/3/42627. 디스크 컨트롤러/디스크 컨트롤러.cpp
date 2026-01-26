#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
struct compare {
    bool operator()(const vector<int>& a, const vector<int>& b) const {
        if (a[1] != b[1]) return a[1] > b[1]; // 소요시간 짧은 게 우선
        return a[0] > b[0];                  // 요청 시각 빠른 게 우선
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    sort(jobs.begin(), jobs.end());

    priority_queue<vector<int>, vector<vector<int>>, compare> pq;

    int index = 0;
    int current_time = 0;
    int sum = 0;
    while (index < jobs.size() || !pq.empty())
    {
        while ( index < jobs.size() && jobs[index][0] <= current_time) //지금시간에 들어올 수 있는 작업 모두 넣음
        {
            pq.push(jobs[index]);
            index++;
        }
       
        if (!pq.empty())
        {
            vector<int>temp = pq.top();
            pq.pop();
            current_time += temp[1];
            sum += current_time - temp[0];
        }
        else
        {
            current_time++;
        }
    }

    answer = sum / jobs.size();
    return answer;
}