#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que; //자동정렬,begin , end로 접근가능
    multiset<int>::iterator iter; //큐의 위치를 가리키는 반복자
    string sub;

    for(auto s : arguments) { //문자를 하나씩 해석
        sub =s.substr(0, 2);
        if(sub=="I ") 
            que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) 
        { 
            que.erase(--que.end());  //멀티셋에서 맨뒤제거
        }
        else if(que.size()>0) 
        { 
            que.erase(que.begin());  //멀티셋에서 맨앞제거
        }
    }

    if(que.size()==0) 
    { answer.push_back(0); answer.push_back(0); } //멀티셋이 비어있다면 0,0출력
    else { 
        iter = --que.end();  //멀티셋에서 최대값 , 최소값 출력
        answer.push_back(*iter); 
        iter = que.begin(); 
        answer.push_back(*iter);
    }

    return answer;
}