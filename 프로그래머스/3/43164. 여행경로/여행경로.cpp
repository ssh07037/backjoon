#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
bool check[10000];
int max_count = 0;
string max_country="";
void dfs(vector<vector<string>> tickets, int depth , string current_country, string countries)
{
   if (max_count < depth) 
   {
       max_count = depth;
       max_country=countries;
    }
    
    for(int i=0; i<tickets.size(); i++)
    {
        if(tickets[i][0] == current_country && check[i] == false)
        {
            check[i] = true;
             dfs(tickets,depth+1,tickets[i][1],countries + tickets[i][1]);
            check[i] = false;
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(),tickets.end());
    dfs(tickets,1,"ICN","ICN");
    for(int i=0; i<max_country.size(); i+=3)
           answer.push_back(max_country.substr(i,3));
    return answer;
}