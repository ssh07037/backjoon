#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    
    unordered_map<string,int>hash;
    int count = 1;
    for(auto a : phone_book)
    {
        hash[a] = count;
        count++;
    }
    
    for(int i=0; i<phone_book.size(); i++) //119 , 0767 , 11955...
    {
        string word = "";
        for(auto b : phone_book[i]) //119
        {
            word += b;
           // cout << hash[word] << endl;
            //cout << word << " " << i <<" " << hash[word] << endl;
            
            if(hash[word] && i != hash[word]-1)
            {
                answer= false;
            }
        }
    }
    
    return answer;
}