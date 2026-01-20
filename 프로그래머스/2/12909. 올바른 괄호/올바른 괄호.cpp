#include<string>
#include<queue>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    // 일단 시작이 ) 이거면 안되고 끝이 ( 면 안됨
    //홀수번째에 내 짝이 있어야한다
    
    queue<char>q;
    q.push(s[0]);
    
    if(s[0] == ')')
        return false;
    int index = 1;
    while(index < s.size())
    {
        if(s[index] == ')')
        {
            if(q.empty())
            {
                answer= false;
               return answer;
            }
            else
            {
                q.pop();
            }
        }
        else
        {
            q.push(s[index]);
        }
        index++;
    }
    
    if(!q.empty())
    {
        answer= false;
    }
    else
    {
        answer = true;
    }
    //예외사항으로 첫번째에 ) 가 들어오면 return false
    //( 가 들어오면 )를 받을 떄 까지 계속 push

    return answer;
}