#include <string>
#include <vector>
#include <iostream>
using namespace std;
int CountWord(const vector<string>& board, char type){
    int count = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            if(board[i][j] == type)
                count++;
        }
    }
    return count;
}
bool CheckWin(const vector<string>& board, char type) {
    // 1. 가로/세로 검사
    for (int i = 0; i < 3; i++) 
    {
        if (board[i][0] == type && board[i][1] == type && board[i][2] == type) 
            return true; // 가로
        if (board[0][i] == type && board[1][i] == type && board[2][i] == type) 
            return true; // 세로
    }

    // 2. 대각선 검사
    if (board[0][0] == type && board[1][1] == type && board[2][2] == type) 
        return true;
    if (board[0][2] == type && board[1][1] == type && board[2][0] == type) 
        return true;

    return false;
}
int solution(vector<string> board) {
    int answer = -1;
    bool OBingo = CheckWin(board,'O');
   
    bool XBingo = CheckWin(board,'X');
    int x = CountWord(board,'X');
    int o = CountWord(board,'O');
    
    if(XBingo && OBingo)
    {
        return 0;
    }
     else if(XBingo)
     {
        if(x == o)
            return 1;
         else
            return 0;
     }
    else if(OBingo)
    {
        if(x == o-1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(x == o || o-1 == x)
            return 1;
        else
            return 0;
    }
    return answer;
}