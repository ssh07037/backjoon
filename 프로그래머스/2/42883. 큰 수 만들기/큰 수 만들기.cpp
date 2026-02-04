#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    //인간 관점에서 k수 + 1만큼 범위에서 가장 큰 값이 있는 위치까지 제거
    //k=3 4185 -> 4,1제거
    
    //다음값이 더 크면 제거?
    
    vector<int>stack;
    int index =0;
    stack.push_back(number[index] - '0');
    
    while(index < number.size()-1 && k > 0)
    {
        index++;
        while( !stack.empty() && k>0 && stack.back() < number[index]- '0')
        {
            stack.pop_back();
            k--;
        }
        stack.push_back(number[index]- '0');
    }
    
    //for(auto a : stack)
    //    cout << a << endl;
    
    //cout << "남은횟수 " << k << endl;
    while(index < number.size()-1)
    {
        index++;
        stack.push_back(number[index]- '0');
    }
    while(k > 0)
    {
        stack.pop_back();
        k--;
    }
    for(auto a : stack)
        answer += a + '0';
    // k남으면 처리
    return answer;
}