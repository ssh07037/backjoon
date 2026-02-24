#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    unordered_map<string,bool>m;
    
    string prev_word = words[0];
    m[prev_word] = true;
    
    for(int i=1; i<words.size(); i++)
    {
        string current_word = words[i];
        //cout << "이전단어 " << prev_word << " " << "현재단어" << current_word << endl;
       // cout << prev_word[prev_word.size()-1] << " " <<  current_word[0] << endl;
        if(prev_word[prev_word.size()-1] != current_word[0])
        {
            int person = (i % n) + 1;
            int turn = (i / n) + 1;
            answer.push_back(person);
            answer.push_back(turn);
            return answer;
        }
        else if(m[current_word] == true)
        {
             int person = (i % n) + 1;
            int turn = (i / n) + 1;
            answer.push_back(person);
            answer.push_back(turn);
             return answer;
        }
      
        m[current_word] = true;
        prev_word = current_word; 
    }
    
   
    answer.push_back(0);
    answer.push_back(0);
    //n = 끝말잇기 하는 사람 수
    //words = 끝말잇기 단어
    
    //중복해서 말했거나 끝말잇기와 틀린단어를 말한사람을 추출하라
    
    
    
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다. 
    for(auto a : answer)
    {
        cout << a;
    }

    return answer;
}