#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;

    sort(rocks.begin(), rocks.end());

    int left = 0;
    int right = distance;

    while (left <= right) 
    {
        int mid = (left + right) / 2;   
        int prev = 0;                 
        int removed = 0;                // 제거한 바위 수

        for (int rock : rocks) 
        {
            if (rock - prev < mid) 
            {
                removed++;              // 간격보다 작은바위 제거
            }
            else 
            {
                prev = rock;            // 제거한게 아니라면 값 갱신
            }
        }

        // 마지막 바위
        if (distance - prev < mid)
            removed++;

        if (removed > n) 
        {
            right = mid - 1;
        } 
        else 
        {
            answer = mid;
            left = mid + 1;
        }
    }

    return answer;
}