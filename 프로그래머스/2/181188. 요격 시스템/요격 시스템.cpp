#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    
    sort(targets.begin(), targets.end(), [](auto& a, auto& b){
        return a[1] < b[1];
    });

    int answer = 0;
    int pos = -1;

    for(auto& t : targets)
    {
        if(pos <= t[0])
        {
            answer++;
            pos = t[1];
        }
    }

    return answer;
}