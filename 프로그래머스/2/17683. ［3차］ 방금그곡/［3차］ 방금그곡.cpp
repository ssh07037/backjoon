#include <string>
#include <sstream>
#include <vector>
#include <set>
#include<map>
#include <iostream>
using namespace std;

struct Info
{
    int time;
    int index;
    string title;
};

string Convert(const string& s)
{
    string result;
    for (int i = 0; i < s.size(); i++)
    {
        if (i + 1 < s.size() && s[i + 1] == '#')
        {
            result += s[i] + 32; // A# → a
            i++;
        }
        else
        {
            result += s[i];
        }
    }
    return result;
}

bool IsSheet(int& time , string& m ,string& sheet)
{
    //abcdefg 와 cdefgab 비교하기
        
    //sheet를 A# -> a  , C#->c , D#->d , F# -> f ,G# -> g 로 변환한다
     //1.끝시간과 시작시간의 차이 (플레이시간)만큼 musicinfo를 쌓는다
    
    m = Convert(m);
    sheet = Convert(sheet);
    
    int count = 0;
    int index = 0;
    string m2 = "";
    
    //sheet 시간만큼 쌓기
    while(count < time)
    {
        if(index >=sheet.size())
        {
            index = 0;
        }
        m2 += sheet[index];        
        count++;
        index++;
    }
    if(m2.find(m) == std::string::npos)
    {
        return false;
    }
    else
    {
        return true;
    }   
}

int GetTime(string startTime,string endTime)
{
    int time1 = 0;
    int time2 = 0;
    
    time1 = (startTime[0] - '0') * 600 + (startTime[1] - '0') * 60  + (startTime[3]- '0' )* 10 + startTime[4] - '0';
    time2 = (endTime[0] - '0') * 600 + (endTime[1] - '0') * 60  + (endTime[3]- '0' )* 10 + endTime[4] - '0';
    
    return time2 - time1;    
}
string solution(string m, vector<string> musicinfos) {

    string answer = "(None)";
    int bestTime = 0;
    int bestIndex = 0;
    //1.같은 멜로디 , 2.재생시간긴것 , 3.먼저입력된것
    for(int i=0; i<musicinfos.size(); i++)
    {
        string info = musicinfos[i];
        stringstream ss(info);
        
        string token;
        
        string startTime;
        string endTime;
        string title;
        string sheet;
        
        
        getline(ss, startTime, ','); //시작 시간
        getline(ss, endTime, ','); //끝 시간
        getline(ss, title, ','); //제목
        getline(ss, sheet, ','); //가사
        
        //1.시간얻음
        int time = GetTime(startTime,endTime);
        //2.시간에따라 가사 증가 , 찾기
        if(IsSheet(time , m,sheet)) //시트가 내가 들은게 맞다면
        {
            if (time > bestTime) //베스트 타임보다 적은지 확인
            {
                bestTime = time;
                 bestIndex = i;
                answer = title; //순서는 info순서로 돌기에 어차피 보장됨
            }
        }
        
    }
   
    return answer;
}
