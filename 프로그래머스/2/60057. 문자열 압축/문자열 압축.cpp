#include <string>
#include <vector>
#include<iostream>
using namespace std;
vector<string> Factory(int size , const string& s)
{
    vector<string>temp;
    for(int i=0; i<s.size(); i+=size)
    {
        //cout <<s.substr(i,size) << endl;
        temp.push_back(s.substr(i,size));
    }
    return temp;
}
int solution(string s) {
    int answer = s.size();
    
    
    vector<string>words;
    
    for(int i=1; i<=s.size()/2; i++)
    {
        words = Factory(i,s);
        string before = words[0];
        int count = 1;
        string temp = "";
        for(int j=1; j<words.size(); j++)
        {
            if(before == words[j])
            {
                count++;
            }
            else
            {
                if(count > 1)
                {
                    temp = temp + to_string(count) + before; //문자열조립
                }
                else
                {
                    //cout << "문자연속 끝남 " << temp << "+" <<before << endl;
                    temp = temp + before; //문자열조립
                }
                 before = words[j];
                count = 1;
            }
        }
         if(count > 1)
        {
            temp = temp + to_string(count) + before; //문자열조립
        }
        else
        {        
            temp = temp + before; //문자열조립
        }
        if(temp.size() < answer)
        {
            answer = temp.size();
        }
    }
    
    
    return answer;
}