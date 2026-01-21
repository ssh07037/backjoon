#include <string>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
void printQueue(queue<int> q) {
    while (!q.empty()) {
        cout << "(" << q.front() << ")" << endl;
        q.pop();
    }
    cout << endl;
}

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<int>q;
    for(int i=0; i<bridge_length; i++)
    {
        q.push(0);
    }
    
    int index = 0;
    int sum = 0;
    while(index < truck_weights.size())
    {
        answer++;
        sum -= q.front(); //다리 위 트럭무게
        q.pop();
        
        if(sum <= weight && sum + truck_weights[index] <= weight)
        {
            q.push(truck_weights[index]);
            sum += truck_weights[index];
            index++;
        }
        else
        {
            q.push(0);
        }
        
        //printQueue(q);

    }
    answer += q.size();
    return answer;
}