#include <iostream>
using namespace std;

bool col[12];
bool diag1[25];
bool diag2[25];

int count = 0;

void dfs(int row, int n)
{
    if(row == n)
    {
        count++;
        return;
    }

    for(int c = 0; c < n; c++) // column
    {
        if(col[c] || diag1[row+c] || diag2[row-c+n]) 
            continue;

        col[c] = true;
        diag1[row+c] = true; //오른쪽대각선(1차원 배열로 나타내기)
        diag2[row-c+n] = true; //왼쪽대각선(1차원 배열로 나타내기)

        dfs(row+1, n);

        col[c] = false;
        diag1[row+c] = false;
        diag2[row-c+n] = false;
    }
}
//주 원리는 행+열의 값이 왼쪽아래 대각선으로 똑같은 값이 나옴
// 빼기는 오른쪽아래 대각선으로 똑같은 값이 나옴
//0 1    0 -1
//1 2    1  0
int solution(int n)
{
    dfs(0,n);
    return count;
}