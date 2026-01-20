#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    
    vector<int>count;
    for(int i=0; i<progresses.size(); i++)
    {
        int temp = 0;
        while(progresses[i] < 100)
        {
            progresses[i] += speeds[i];
            temp++;
        }
        count.push_back(temp);
        //cout << temp << endl;
    }
    
    //각 최소횟수를 구함
    
    cout << endl;
    int index= 0;
    int temp = count[0];
    
    while(index < progresses.size())
    {
        int count2 = 0;
        do
        {
            index++;
            count2++;
           // cout << temp << " " << count[index] << " " << index << endl;
        }while (index < count.size() && count[index] <= temp);
        

        answer.push_back(count2);
        temp = count[index];
    }
    
    //최소횟수보다 많은카운트가 다음 인덱스에서 필요하면 그곳을 다시 
    return answer;
}