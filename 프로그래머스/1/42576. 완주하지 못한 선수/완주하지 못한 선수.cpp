#include <string>
#include<algorithm>
#include <vector>
#include<iostream>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    //participant(마라톤 참여선수)
    //completion(마라톤 완주선수)
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<completion.size(); i++)
    {
        if(participant[i] != completion[i])
        {
            answer= participant[i];
            break;
        }
    }
    if(answer == "")
    {
        answer = participant[participant.size()-1];
    }
    
    return answer;
}