#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();

    // 1️⃣ 상·하 조작 비용
    for (int i = 0; i < n; i++) {
        int up = name[i] - 'A';
        int down = 'Z' - name[i] + 1;
        answer += min(up, down);
    }
    //모든 문자 최소 비용

    // 2️⃣ 좌·우 이동 최소값
    int move = n - 1;  // 기본: 오른쪽으로 끝까지 가는 경우
    //조이스틱으로 좌우이동하는것은 한번으로 충분함
    //다시 돌아가는것은 낭비가 됨
    
    
    for (int i = 0; i < n; i++) {
        int next = i + 1;

        while (next < n && name[next] == 'A') {
            next++;
        }

        //  i까지 갔다가 뒤로 돌아가는 경우
        int right_then_left = i * 2 + (n - next);

        //  뒤로 갔다가 다시 오는 경우
        int left_then_right = (n - next) * 2 + i;

        move = min(move, min(right_then_left, left_then_right));
    }

    answer += move;
    return answer;
}
