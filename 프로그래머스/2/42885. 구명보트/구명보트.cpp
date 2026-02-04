#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(),people.end(),greater<int>());
    //50,50,70,80
    
    int index1 = 0;
    int index2 = people.size()-1;
    
    while(index1 <= index2)
    {
        int temp = people[index1];
        if(temp + people[index2] <= limit)
        {
            temp += people[index2];
            index2--;
        }
        //cout << temp << " , " << index1 << " , " << index2 << endl;
        index1++;
        answer++;
    }
    return answer;
}