#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int ax[4] = {1, -1, 0, 0};
int ay[4] = {0, 0, 1, -1};

int solution(vector<string> storage, vector<string> requests) {
    int R = storage.size();
    int C = storage[0].size();

    // 외부 패딩
    vector<string> grid(R + 2, string(C + 2, '.'));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            grid[i + 1][j + 1] = storage[i][j];

    for (auto a : requests)
    {
        char container = a[0];
        vector<pair<int,int>> temp;

        // 외부 공기 탐색
        vector<vector<bool>> check(R + 2, vector<bool>(C + 2, false));
        queue<pair<int,int>> q;
        q.push({0,0});
        check[0][0] = true;

        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++)
            {
                int nx = x + ax[i];
                int ny = y + ay[i];
                
                //범위 체크
                if(nx < 0 || ny < 0 || nx >= R + 2 || ny >= C + 2)
                    continue;

                //가본적 없고 테두리라면
                if(!check[nx][ny] && grid[nx][ny] == '.')
                {
                    check[nx][ny] = true;
                    q.push({nx, ny});
                }
                //테두리가 아니고 , 4분면중 원하는 컨테이너 발견시 테두리로 만들기위한 초석
                else if(grid[nx][ny] == container)
                {
                    temp.push_back({nx, ny});
                }
            }
        }

        // 지게차 vs 크레인
        if(a.size() == 1) {
            for(auto b : temp)
                grid[b.first][b.second] = '.';
        }
        else {
            for(int i = 1; i <= R; i++)
                for(int j = 1; j <= C; j++)
                    if(grid[i][j] == container)
                        grid[i][j] = '.';
        }
    }

    // 남은 컨테이너 수
    int answer = 0;
    for(int i = 1; i <= R; i++)
        for(int j = 1; j <= C; j++)
            if(grid[i][j] != '.') answer++;

    return answer;
}