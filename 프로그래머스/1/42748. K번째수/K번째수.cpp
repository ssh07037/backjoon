#include <string>
#include<algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(auto a : commands)
    {
        vector<int>temp;
        for(int i=a[0]-1; i<=a[1]-1; i++)
        {
            temp.push_back(array[i]);
        }
        sort(temp.begin(),temp.end());
        answer.push_back(temp[a[2]-1]);
    }
    return answer;
}