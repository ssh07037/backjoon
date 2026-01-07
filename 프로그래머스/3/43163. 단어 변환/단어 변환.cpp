#include <string>
#include <vector>
#include <queue>

using namespace std;

int visited[50];

int possible(string a, string b)
{
    int i;
    int cnt = 0;

    for(i=0;i<a.length();i++)
    {
        if(a[i] != b[i]) cnt++;
    }

    if(cnt==1) return 1;
    else return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    queue<pair<string,int>> Q;
    int i;
    string temp;
    int num;

    Q.push(make_pair(begin,0)); //큐 시작에 begin을 넣는다 , count
    while(!Q.empty())
    {
        temp = Q.front().first;
        num = Q.front().second;
        Q.pop();

        if(temp.compare(target) == 0) //두 문자를 사전식으로 비교 (동일하면 0 반환)
        {
            answer = num;
            break;
        }

        for(i=0;i<words.size();i++)
        {
            if(visited[i]) continue; //들른 단어라면 패스
            if(possible(temp, words[i])) //단어가 하나만 다른지 체크
            {
                visited[i] = 1; //들른단어로 기록 후 
                Q.push(make_pair(words[i],num+1)); //큐의 최상단에 놓음
            }
        }
    }
//너비우선탐색
    return answer;
}