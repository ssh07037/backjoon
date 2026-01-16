#include <iostream>
using namespace std;

int GCD(int a, int b){ //유클리드 호재법  나오는 나머지를 계속 최대공약수 구함
    if(a == 0) return b;
    return GCD(b % a, a); //나머지 , 값
}

long long solution(int w,int h)
{
   long long answer = 1;

    int gcd = GCD(w, h); //최대공약수
    answer = ((long)w * h) - ((long)w + h - gcd);
    //나오는 점화식이 가로 + 세로 - 최대공약수만큼 대각선을 씀

   return answer;
}


