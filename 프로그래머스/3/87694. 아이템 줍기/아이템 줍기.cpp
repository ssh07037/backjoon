#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;

    vector<vector<int>> maps(101, vector<int>(101, -1));
    for (auto a : rectangle)
    {
        int x1 = a[0] * 2;
        int y1 = a[1] * 2;
        int x2 = a[2] * 2;
        int y2 = a[3] * 2;
        for (int x = x1; x <= x2; x++)
        {
            for (int y = y1; y <= y2; y++)
            {
                maps[x][y] = 0;
            }
        }
    }
    for (auto a : rectangle)
    {
        int x1 = a[0] * 2;
        int y1 = a[1] * 2;
        int x2 = a[2] * 2;
        int y2 = a[3] * 2;
        for (int x = x1 + 1; x < x2; x++)
        {
            for (int y = y1 + 1; y < y2; y++)
            {
                maps[x][y] = -1;
            }
        }
    }
    queue<pair<int, int>>q;
    q.push(make_pair(characterX * 2, characterY * 2));
    maps[characterX * 2][characterY * 2] = 0;
    int ax[4] = { 1,-1,0,0 };
    int ay[4] = { 0,0,-1,1 };

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == itemX * 2 && y == itemY * 2)
            break;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + ax[i];
            int ny = y + ay[i];

            if (nx < 0 || nx > 100 || ny < 0 || ny > 100) 
                continue;

            if (maps[nx][ny] == 0)
            {
                maps[nx][ny] = maps[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }

    /*for (int y = 50; y >= 0; y--) {  // y축 위쪽부터 출력
        for (int x = 0; x < 50; x++) {
            if (maps[x][y] == -1)
                cout << ". ";   // -1은 빈 칸
            else
                cout << maps[x][y];   // 0이나 1이면 테두리 표시
        }
        cout << endl;
    }*/

    answer = maps[itemX*2][itemY*2]/2;
    //cout << answer << endl;
    return answer;
}