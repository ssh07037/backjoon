#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Mine {
    int dia;
    int iron;
    int stone;
};

int solution(vector<int> picks, vector<string> minerals) {
    vector<Mine> mines;

    for (int i = 0; i < minerals.size(); i += 5) {
        Mine m{0, 0, 0};

        for (int j = i; j < i + 5 && j < minerals.size(); j++) { //젤마지막 3개남는것 예외처리 , 5개씩 2중포문 수행
            if (minerals[j] == "diamond") {
                m.dia   += 1;
                m.iron  += 5;
                m.stone += 25;
            }
            else if (minerals[j] == "iron") {
                m.dia   += 1;
                m.iron  += 1;
                m.stone += 5;
            }
            else { // stone
                m.dia   += 1;
                m.iron  += 1;
                m.stone += 1;
            }
        }
        //내가 한 것처럼 TUPLE 느낌으로 정리
        mines.push_back(m);
    }

    int maxMine = picks[0] + picks[1] + picks[2];
    if (mines.size() > maxMine) {
        mines.resize(maxMine);
    }
    //내가 한 것 처럼 광산 수 제한
    

    // 3️⃣ 돌 곡괭이 기준으로 정렬 (가장 중요한 포인트)
    sort(mines.begin(), mines.end(),
         [](const Mine& a, const Mine& b) {
             return a.stone > b.stone;
         });
    //stone 피로도: [12, 3, 20, 7] -> stone 피로도: [20, 12, 7, 3]

    

    // 4️⃣ 좋은 곡괭이부터 사용
    int answer = 0;
    int idx = 0;

    // 다이아 곡괭이
    for (int i = 0; i < picks[0] && idx < mines.size(); i++, idx++) {
        answer += mines[idx].dia;
    }

    // 철 곡괭이
    for (int i = 0; i < picks[1] && idx < mines.size(); i++, idx++) {
        answer += mines[idx].iron;
    }

    // 돌 곡괭이
    for (int i = 0; i < picks[2] && idx < mines.size(); i++, idx++) {
        answer += mines[idx].stone;
    }

    return answer;
}
