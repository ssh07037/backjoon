#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    //갈섹 격자의 수 , 노란 격자의수 바탕으로 넓이 추출
    
    //20 1->2->4->5->10->20
    vector<pair<int,int>>yellow_extent;
    //1*20일떄의 갈색수 추출 -> 
    for(int i=1; i<=yellow; i++)
    {
        if(yellow % i == 0)
        {
            yellow_extent.push_back(make_pair(i,yellow/i));
        }
    }
    
    int col = 0;
    int row = 0;
    for(auto a : yellow_extent)
    {
        int temp = (a.first+2) *  (a.second+2) - yellow;
        if(temp == brown)
        {
            col = a.first+2;
            row = a.second+2;
        }
    }
    answer.push_back(col);
    answer.push_back(row);
    sort(answer.begin(),answer.end(),greater<int>());
    
    //그런식으로 해서 옐로우2일떄의 수를 가정한다면
    //2  1->2
    //1*2일떄의 갈색 수 추출 가로수+2 = 갈색가로수 세로수+2=갈섹세로수   (2+2) * (2+1) - 노란색
    
    //약수들이 곧 모양
    return answer;
}