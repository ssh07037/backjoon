#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

bool check[7];
string temp;
void dfs(const string& numbers,vector<string>& vs)
{
    for(int i=0; i<numbers.size(); i++)
    {
        if(check[i] == true)
            continue;
        check[i] = true;
        temp+=numbers[i];
        vs.push_back(temp);
        dfs(numbers,vs);
        //-----------------
        temp.pop_back();
        check[i] = false;
    }
}


int solution(string numbers) {
    int answer = 0;
    vector<string>vs;
    dfs(numbers,vs);
    
    set<int>s;
    for(int i=0; i<vs.size(); i++)
    {
        int number = stoi(vs[i]);
        bool sosu = true;
        if(number == 1 || number == 0)
            continue;
        for(int i=2; i<number; i++)
        {
            if(number % i == 0)
            {
                sosu = false;
                break;
            }
        }
        if(sosu == true)
        {
             s.insert(number); 
        }
    }
    answer = s.size();
    return answer;
}