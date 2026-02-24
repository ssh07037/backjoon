#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;
int ax[4] = {1,-1,0,0};
int ay[4] = {0,0,1,-1};
bool check[5][5];
bool isRight = true;
void bfs(const vector<string>& places,int row, int col,int limit_x , int limit_y,int count)
{
    cout << "bfs 접근" << endl;
    if(count == 2)
        return;
    for(int i=0; i<4; i++)
    {
        int temp_row = row + ax[i];
        int temp_col = col + ay[i];
        if(temp_row >= 0 && temp_row < limit_x
          && temp_col >= 0 && temp_col < limit_y) //범위안인지 체크
        {
            if(check[temp_row][temp_col] == false) //한번도 들른적 없는곳인지 체크
            {
                check[temp_row][temp_col] = true;
                //cout << count+1 << " " << temp_row << " " << temp_col << " " << places[temp_row][temp_col] << endl;
                if(places[temp_row][temp_col] == 'X') //파티션 만나면
                {
                    continue;
                }
                else if(places[temp_row][temp_col] == 'O') //빈자리 만나면 탐색계속
                {
                    bfs(places,temp_row,temp_col,limit_x,limit_y,count+1);
                }
                else if(places[temp_row][temp_col] == 'P') //거리가 지켜지지 않았다면
                {
                    isRight = false;
                    return;
                }
            }
        }
    }
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    //대기실 5개 , 각 대기실 크기는 5x5
    //맨해튼거리 
    
    //p가 응시자
    //o 빈 테이블
    //x 파티션
    for(int k=0; k<places.size(); k++) //대기실 수
    {
        for(int i=0; i<places.size(); i++) //행
        {
            for(int j=0; j<places[0].size(); j++) //열
            {
                memset(check,false,sizeof(check));
                if(places[k][i][j] == 'P')
                {
                    check[i][j] = true;
                    bfs(places[k],i,j,5,5,0);
                    cout << "-------" << endl;
                }
            }
        }
        cout << isRight << endl;

        if(isRight == true)
        {
            answer.push_back(1);
        }       
        else
        {
            answer.push_back(0);
        }
        isRight = true;
    }

    //p를 기준으로 별모양안에 또다른 p가 있으면 안된다
    
    return answer;
}