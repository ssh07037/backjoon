#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    //12345
    //21232425
    //3311224455
    int a[5] = {1,2,3,4,5};
    int b[8] = {2,1,2,3,2,4,2,5};
    int c[10] = {3,3,1,1,2,2,4,4,5,5};
    
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    for(int i=0; i<answers.size(); i++)
    {
        if(a[i%5] == answers[i])
        {
            acount++;
        }
        if(b[i%8] == answers[i])
        {
            bcount++;
        }
        if(c[i%10] == answers[i])
        {
            ccount++;
        }
    }
//cout << acount << " " << bcount << " " << ccount << endl;
    if(acount >= bcount && acount >= ccount)
    {
        answer.push_back(1); 
    }
    if(bcount >= ccount && bcount >= acount)
    {
        answer.push_back(2);
    }
    if(ccount >= bcount && ccount >= acount)
    {
        answer.push_back(3);
    }
    return answer;
}