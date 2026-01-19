#include <string>
#include <vector>
#include <algorithm>
#include<iostream>
#include <unordered_map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    unordered_map<string,vector<string>>hash;
    vector<string>type;
    for(auto a : clothes)
    {
        hash[a[1]].push_back(a[0]);
        auto b = find(type.begin(), type.end(),a[1]);
        //cout << a[1] << endl;
        if(b == type.end())
        {
            type.push_back(a[1]);
            cout << a[1] <<" 종류 추가함 " << endl;
        }
    }
    
    answer = 1;
    for(auto a : type)
    {
        answer *= hash[a].size()+1; //3개의의상중 2개의상착용을 1개의상은 투명의상으로 취급
    }
    answer--;
    
   
    return answer;
}
