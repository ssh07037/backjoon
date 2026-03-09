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
        diag2[row-c+n] = true; //왼쪽대각선

        dfs(row+1, n);

        col[c] = false;
        diag1[row+c] = false;
        diag2[row-c+n] = false;
    }
}

int solution(int n)
{
    dfs(0,n);
    return count;
}