#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <climits>
using namespace std;
int toTime(const string& s) 
{
    return (s[0]-'0')*600 + (s[1]-'0')*60 + (s[3]-'0')*10 + (s[4]-'0');
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    //과제는 시작하기로 한 시각이 되면 시작
    //새로운 과제가 시작할 시간이 되면 기존것 멈추고 새 과제 시작
    //진행중인 과제가 끝났는데 기존에 멈춘 과제가 있다면 멈춘것부터 시작(공통으로 새 과제가 있다면 새 과제부터)
    
    //1.새과제
    //2.기존과제
    sort(plans.begin(),plans.end(),[](auto& a , auto& b){
        int a_time = toTime(a[1]);
        int b_time = toTime(b[1]);
         return a_time < b_time;
    }); //정렬
    
 
   vector<pair<string,int>> stack; // {과제명, 남은시간}

    for (int i = 0; i < plans.size(); i++) 
    {
        string name = plans[i][0];
        int start = toTime(plans[i][1]);
        int play = stoi(plans[i][2]);
        
        int nextstart = INT_MAX;
        if(i+1 < plans.size())
        {
            
            nextstart=toTime(plans[i+1][1]);
        }
        //1220 , 1230
         int time = nextstart - start;

        // 주어진 시간안에 지금작업을 할 수 있다면
        if (play <= time) {
            answer.push_back(name);
            time -= play;

            // 남은 시간 동안(다음작업 전까지) 멈춘 과제 처리
            while (!stack.empty() && time > 0) 
            {
                string s_name = stack.back().first;
                int s_time = stack.back().second;
                stack.pop_back();

                if (s_time <= time) 
                { //남은시간안에 끝낼 수 있다면
                    time -= s_time;
                    answer.push_back(s_name);
                } 
                else 
                { //남은시간안에 못끝내면 시간보내고 다시 스택에 넣음
                    stack.push_back({s_name, s_time - time});
                    break;
                }
            }
        }
        else {
            // 주어진 시간안에 이 작업을 못끝내 다음작업을 해야한다면 스택에 저장
            stack.push_back({name, play - time});
        }
    }

     while (!stack.empty())
     {
        answer.push_back(stack.back().first);
        stack.pop_back();
    }    
    
    return answer;
}