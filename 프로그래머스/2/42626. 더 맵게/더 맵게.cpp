#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    //가장맵지않은 스코빌지수 + 두번쨰로 맵지않은 스코빌지수*2
    
    //특정 스코빌지수까지 섞음
    priority_queue <int, vector<int>,greater<int>> pq;
    for(auto a : scoville)
    {
        pq.push(a);
        //cout << a << endl;
    }
    
    int min = 0;
    while(pq.top() < K)
    {
        int temp1 = pq.top();
        pq.pop();
        int temp2 = pq.top();
        pq.pop();
        
        
        int temp3 = temp1 +temp2*2;
        pq.push(temp3);
        answer++;
        
        if(pq.size() == 1)
        {
            break;
        }
    }
    
    if(pq.top() < K)
    {
        answer= -1;
    }
    
    
    return answer;
}