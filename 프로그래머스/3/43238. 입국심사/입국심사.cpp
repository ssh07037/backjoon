#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
using namespace std;
//0 1 2 3 4 5 6 7 8 9


long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long left = 0;
    long long right = (long long)*max_element(times.begin(), times.end()) * n;
    
    while (left <= right) 
    {
        long long mid = (left + right) / 2;
        long long count = 0;

        for (int time : times) 
        {
            count += mid / time;
        }

        if (count >= n) 
        {
            answer = mid;      // 가능한 시간 저장
            right = mid - 1;   // 더 줄여보기
        } 
        else 
        {
            left = mid + 1;    // 시간이 부족
        }
    }
    return answer;
}