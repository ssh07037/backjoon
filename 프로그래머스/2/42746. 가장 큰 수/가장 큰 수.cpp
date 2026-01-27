#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const string& a, const string& b) {
    return a + b > b + a;
} //2개씩 비교 , 정렬 , 예)610  106 비교 = 610   102 , 210 비교 = 210

string solution(vector<int> numbers) {
    vector<string> v;
    string answer;

    for (int x : numbers)
        v.push_back(to_string(x));

    sort(v.begin(), v.end(), compare);

    
    if(v[0] == "0")
    {
        answer = "0";
        return answer;
    }
    
    for (auto& s : v)
        answer += s;

    return answer;
}