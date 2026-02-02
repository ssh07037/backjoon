#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int dfs(int index, string word, unordered_map<string,int>& answers) {
    answers[word] = index;
    cout << word << " " << index << endl;
    if (word.length() < 5) {
        index = dfs(index + 1, word + 'A', answers); //a로 시작하는것 서브트리 작성
        index = dfs(index + 1, word + 'E', answers); //e로 시작하는것 서브트리 작성,,,
        index = dfs(index + 1, word + 'I', answers);
        index = dfs(index + 1, word + 'O', answers);
        index = dfs(index + 1, word + 'U', answers);
    }
    return index;
}

int solution(string word) {
    int answer = 0;
    unordered_map<string,int> answers;
    dfs(0, "", answers);
    return answers[word];
}