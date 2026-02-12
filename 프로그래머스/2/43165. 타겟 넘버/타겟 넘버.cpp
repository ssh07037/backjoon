#include <string>
#include <vector>
#include <iostream>

using namespace std;
int counts;
void dfs(const vector<int>& numbers, int target,int current_number , int count,string operate,vector<int>temp)
{
    if(operate == "plus")
    {
        current_number += numbers[count];
        temp.push_back(numbers[count]);
    }
    else if(operate == "minus")
    {
        current_number -= numbers[count];
        temp.push_back(numbers[count] * -1);
    }
    count++;
    if(count == numbers.size() && current_number == target)
    {
      //  for(auto a : temp)
      //      cout << a << endl;
        //cout << endl;
        counts++;
        return;
    }
    else if(count == numbers.size())
    {
        return;
    }
    
     dfs(numbers,target,current_number,count,"plus",temp);
    dfs(numbers,target,current_number,count,"minus",temp);
    
    return;
}
int solution(vector<int> numbers, int target) {
    int answer = 0;
    vector<int>temp;
    dfs(numbers,target,0,0,"plus",temp);
    dfs(numbers,target,0,0,"minus",temp);
    answer = counts;
    return answer;
}