#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> bridge;
    int time = 0, sum = 0;
    int index = 0;

    // 초기 bridge에 0으로 채워 넣음 (길이만큼 자리 유지)
    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }

    while (index < truck_weights.size()) {
        // 다리 앞쪽 트럭이 나감
        sum -= bridge.front();
        bridge.pop();

        // 다음 트럭을 올릴 수 있으면 올림
        if (sum + truck_weights[index] <= weight) {
            bridge.push(truck_weights[index]);
            sum += truck_weights[index];
            index++;
        } else {
            bridge.push(0); // 아무 트럭도 못 올라가면 빈 자리
        }

        time++;
    }

    // 마지막 트럭이 올라간 후 다리 끝까지 가는 시간 추가
    time += bridge_length;

    return time;
}
