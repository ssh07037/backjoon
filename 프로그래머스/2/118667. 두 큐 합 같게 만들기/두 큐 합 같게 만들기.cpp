#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    queue<long>q1;
    queue<long>q2;
    //길이가 같은 두 개의 큐
    //하나의 큐를 pop , 다른큐에 insert 작업으로 원소의 합이 같게 만들기
    
    //최소횟수 리턴
    
    //3,2,7,2  4,6,5,1
    //14 , 16 //무조건 pop은 앞에수만가능하니까 앞에수를 비교해서 총합이 적은곳으로 더 큰값을 이동
    //3,2,7,2,4  6,5,1     18,12
    long sum1= 0;
    long sum2 = 0;
    for(auto a : queue1) //각 큐의 합을 구하면서 큐로 변환
    {
        sum1 += a;
        q1.push(a);
    }
    for(auto b : queue2)
    {
        sum2 += b;
        q2.push(b);
    }
    while(sum1 != sum2)
    {
        if(sum1 > sum2)
        {
            long imsi = q1.front();  // front()로 값을 가져옴
            q1.pop();
            q2.push(imsi); //뺀걸 넣음
            sum1 -= imsi;
            sum2 += imsi;
        }
        else if(sum1  < sum2)
        {
            long imsi = q2.front();  // front()로 값을 가져옴
            q2.pop();
            q1.push(imsi);
            sum1 += imsi;
            sum2 -= imsi;
        }
        if(q1.empty() || q2.empty() || answer == 600000)
        {
            return -1;
        }
       
        answer++;
       
    }
    
    return answer;
}