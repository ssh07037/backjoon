#include <vector>
using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> triangle(n);
    vector<int> answer;

    // 삼각형 형태를 위한 초기화
    for (int i = 0; i < n; ++i) {
        triangle[i] = vector<int>(i + 1, 0); //2중 배열을 삼각형모양으로 0으로 초기화
    }

    int num = 1;
    int x = -1, y = 0;

    for (int i = 0; i < n; ++i) { //6번,5번,4번,3번,2번,1번
        for (int j = i; j < n; ++j) { //
            if (i % 3 == 0) 
            {        //아래로
                x++;
            } 
            else if (i % 3 == 1) 
            {       //오른쪽으로
                y++;
            } 
            else
            {       //위로
                x--;
                y--;
            }
            triangle[x][y] = num++;
        }
    }

    // 결과 벡터로 변환
    for (auto& row : triangle) {
        for (int val : row) {
            answer.push_back(val);
        }
    }

    return answer;
}
