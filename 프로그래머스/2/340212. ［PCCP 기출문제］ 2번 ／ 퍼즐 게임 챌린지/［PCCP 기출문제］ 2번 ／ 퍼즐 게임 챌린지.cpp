#include <vector>
#include <algorithm>

using namespace std;

// 특정 level일 때 모든 퍼즐을 푸는 데 걸리는 총 시간을 계산하는 함수
bool isPossible(const vector<int>& diffs, const vector<int>& times, long long limit, int level) {
    long long total_time = 0;
    
    for (int i = 0; i < diffs.size(); i++) {
        if (diffs[i] <= level) {
            total_time += times[i]; 
        } else {
            int diff_gap = diffs[i] - level;
            int time_prev = (i == 0) ? 0 : times[i - 1];
            // 공식: (틀린 횟수 * (현재 시간 + 이전 시간)) + 현재 시간
            total_time += (long long)diff_gap * (times[i] + time_prev) + times[i];
        }
        
        // 계산 도중 이미 limit을 초과하면 더 계산할 필요 없음
        if (total_time > limit) return false;
    }
    return total_time <= limit;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int low = 1;
    int high = 100000; // diffs[i]의 최대값
    int answer = high;

    while (low <= high) {
        int mid = (low + high) / 2; // "5의 branch" 처럼 중간값을 선택
      
        if (isPossible(diffs, times, limit, mid)) {
            // 시간 내에 해결 가능하므로, 더 낮은 숙련도가 있는지 확인 (반으로 최대점을 낮춤)
            answer = mid;
            high = mid - 1;
        } else {
            // 시간 부족, 숙련도를 높여야 함 (반으로 최저점을 올림)
            low = mid + 1;
        }
    }
    
    return answer;
}