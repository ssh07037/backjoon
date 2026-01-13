// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cctype>


using namespace std;
void Calculate(vector<string>& temp, int type)
{
    if (type == 1)
    {
        for (int i = 1; i < temp.size(); i+=2)
        {
            if (temp[i] == "*")
            {
                string cal = to_string(stoll(temp[i - 1]) * stoll(temp[i + 1]));
                temp[i - 1] = cal;
                temp.erase(temp.begin() + i, temp.begin() + i + 2);
                i-=2;
            }
        }
    }
    else if (type == 2)
    {
        for (int i = 1; i < temp.size(); i += 2)
        {
            if (temp[i] == "+")
            {
                string cal = to_string(stoll(temp[i - 1]) + stoll(temp[i + 1]));
                temp[i - 1] = cal;
                temp.erase(temp.begin() + i, temp.begin() + i + 2);
                i -= 2;
            }
        }
    }
    else if (type == 3)
    {
        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] == "-")
            {
                string cal = to_string(stoll(temp[i - 1]) - stoll(temp[i + 1]));
                temp[i - 1] = cal;
                temp.erase(temp.begin() + i, temp.begin() + i + 2);
                i -= 2;
            }
        }
    }
    return;

}


vector<string> Split(const string& expression)
{
    string number;
    vector<string> express;
    for (char a : expression)
    {
        if (isdigit(a))
        {
            number += a;
        }
        else
        {
            express.push_back(number);
            express.push_back(string(1, a));
            number = "";
           
        }
    }
    express.push_back(number);

    return express;
}


long long solution(string expression) {
    long long answer = 0;

    vector<string>express = Split(expression);

    queue<pair<vector<string>, vector<int>>> q;

    //100,-,200,... , false,false,false
    q.push(make_pair(express, vector<int>()));
    long long max = 0;

    while (!q.empty())  // 큐가 비어있지 않으면 반복
    {
        pair<vector<string>, vector<int>> tempA = q.front();  // 큐에서 수식과 우선순위 조합을 가져옴
        q.pop();  // 큐에서 제거

        for (int i = 1; i <= 3; i++)  // 3가지 연산자에 대해 반복
        {
            pair<vector<string>, vector<int>> temp = tempA;  // 현재 수식과 우선순위 조합 복사
            if (find(temp.second.begin(), temp.second.end(), i) != temp.second.end())
                continue;  // 이미 사용한 우선순위 조합이면 건너뜀

            Calculate(temp.first, i);  // 현재 우선순위로 계산

            if (temp.first.size() == 1)  // 계산 결과가 하나만 남으면 (최종 결과)
            {
                long long num = stoll(temp.first[0]);  // 숫자로 변환
                if (num < 0)
                    num = num * -1;  // 음수면 절댓값으로 변환
                max = num > max ? num : max;  // 최대값 갱신
            }

            temp.second.push_back(i);  // 현재 우선순위 조합에 추가

            q.push(temp);  // 큐에 삽입
        }
    }


    cout << max << endl;
    return answer = max;
}

