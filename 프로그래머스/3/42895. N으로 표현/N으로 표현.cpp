#include <string>
#include <vector>

using namespace std;
int minCnt = 9;
void dp(int N , int number ,int cnt, int current_number)
{
    if(cnt > 8)
    { 
        return; 
    }
    if(current_number == number)
    { 
        minCnt = min(minCnt, cnt); 
    }
   
    int operand = 0;
    
    for(int i=1; i<=9; i++){ //5, 55, 555 만들기 
        operand = operand*10 + N; 
        dp(N, number, cnt + i, current_number + operand); 
        dp(N, number, cnt + i, current_number - operand); 
        if(current_number != 0)
        { 
            dp(N, number, cnt + i, current_number * operand); 
            dp(N, number, cnt + i, current_number / operand); 
        }
    }
}
int solution(int N, int number) {
    int answer = 0;
    
    dp(N , number ,0, 0);
    answer = minCnt;
    if(minCnt > 8)
        answer = -1;
    return answer;
}