#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> scores) {
    vector<int> wan = scores[0];  // 완호의 점수 저장
    int sumWan = wan[0] + wan[1];

    // 1. 근무 태도 점수 기준 내림차순 정렬, 동점일 경우 동료 평가 점수 오름차순
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0]) return a[1] < b[1];  // 근무 태도 점수가 같으면 동료 평가 점수 오름차순
        return a[0] > b[0];  // 근무 태도 점수 기준 내림차순
    });

    // 2. 탈락자 필터링 (단일 루프 O(N))
    int maxPeerScore = 0;  // 현재까지의 동료 평가 점수 최댓값
    vector<vector<int>> validScores;  // 인센티브 받을 수 있는 직원 리스트

    for (const auto& s : scores) {
        if (s[1] < maxPeerScore) continue;  // 동료 평가 점수가 현재 최댓값보다 낮으면 탈락
        maxPeerScore = max(maxPeerScore, s[1]);  // 최댓값 갱신
        validScores.push_back(s);
    }

    // 3. 완호가 포함되어 있는지 확인
    auto it = find(validScores.begin(), validScores.end(), wan);
    if (it == validScores.end()) return -1;  // 완호가 탈락했다면 -1 반환

    // 4. 석차 계산을 위해 총점 기준 내림차순 정렬
    sort(validScores.begin(), validScores.end(), [](const vector<int>& a, const vector<int>& b) {
        return (a[0] + a[1]) > (b[0] + b[1]);  // 총점 기준 내림차순 정렬
    });

    // 5. 석차 계산
    int rank = 1;
    int count = 0;  // 동석차 개수
    int prevSum = validScores[0][0] + validScores[0][1];

    for (int i = 0; i < validScores.size(); i++) {
        int sum = validScores[i][0] + validScores[i][1];

        if (i > 0 && sum < prevSum) {  // 새로운 점수 그룹 시작
            rank += count;
            count = 1;
        } else {  // 동석차
            count++;
        }

        if (validScores[i] == wan) return rank;
        prevSum = sum;
    }

    return rank;
}