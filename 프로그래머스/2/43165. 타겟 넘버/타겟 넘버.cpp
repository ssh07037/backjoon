#include <vector>
using namespace std;

int answer = 0;

void dfs(const vector<int>& numbers, int index, int current, int target) {
    if(index == numbers.size()) 
    {
        if(current == target) 
            answer++;
        return;
    }
    dfs(numbers, index + 1, current + numbers[index], target);
    dfs(numbers, index + 1, current - numbers[index], target);
}

int solution(vector<int> numbers, int target) 
{
    answer = 0;
    dfs(numbers, 0, 0, target);
    return answer;
}