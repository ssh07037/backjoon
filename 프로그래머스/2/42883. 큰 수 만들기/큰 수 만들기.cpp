#include <string>
#include <vector>
#include<deque>
#include<iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    deque<char>a;
    a.push_back(number[0]);
    int count = 0;
    int index = 1;
    
    //k와 number수가 같다면
    //2 2
    while(count != k) //a.size()가 2가 아니면
    {
        if(!a.empty() && a.back() < number[index])  //41 , 7                                             
        {
            while (!a.empty() && a.back() < number[index]) 
            {
                    a.pop_back(); //4 , 7
                    count++;
                    if(count == k)
                    {
                        break;
                    }
            }
        }
         a.push_back(number[index]); //98754 3214
         index++;
    }
    //8개 값이 들어감
    cout << a.size() << endl;
    while(index < number.size())
    {
        a.push_back(number[index]);
        index++;
    }
    count = 0;
    while(count != number.size()-k)
    {
        
        answer += a.front();
        a.pop_front();
        count++;
    }
    return answer;
    //98759812 k=1 이면 5를 지우고
    //k=2면 1,2를 지워야한다
    
    //작아지면 상관없고 뒷값이 커지면 상관있다 앞값을 지운다
    
    //4177252841
    //417 문제발생 1을 지움
    //47 문제발생 4를 지움
    //7725 문제발생 2를 지움
    //77528 문제발생 2를 지움
    //7758
    
    //1924
    //19 문제발생 1을 지움
    //924 문제발생 2를지움
    //94
    
    //1231234
    //12 문제발생 1을 지움
    //23 문제발생 2을 지움
    //312 문제발생 1을 지움
   
}