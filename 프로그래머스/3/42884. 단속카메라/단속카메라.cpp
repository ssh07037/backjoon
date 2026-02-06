#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
using namespace std;
int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end(), [](auto& a, auto& b) {
        return a[1] < b[1]; // 나가는 지점 기준 정렬
    });

    
    int answer = 0;
    int camera = -30001;
    
    
    //끝점과 시작점 비교 시작점이 끝점보다 크면 새로운 카메라 설치
    for (auto& r : routes) 
    {
        if (camera < r[0]) 
        {  
            camera = r[1];    
            answer++;
        }
    }
    return answer;
}