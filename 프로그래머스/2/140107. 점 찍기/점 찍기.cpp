#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) 
{
    long long answer = 0;
    long long distance = 1LL * d * d;

    for(long long x = 0; x <= d; x += k)
    {
        long long temp = distance - x * x;
        long long max_y = sqrt(temp);  // 먼저 정수 저장
        answer += max_y / k + 1;
    }

    return answer;
}