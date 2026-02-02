#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
    vector<int> clothes(n + 1, 1); // 1번~n번 사용

    for (int r : reserve)
        clothes[r]++;

    for (int l : lost)
        clothes[l]--;

    for (int i = 1; i <= n; i++)
    {
        if (clothes[i] == 0)
        {
            if (i > 1 && clothes[i - 1] == 2)
            {
                clothes[i - 1]--;
                clothes[i]++;
            }
            else if (i < n && clothes[i + 1] == 2)
            {
                clothes[i + 1]--;
                clothes[i]++;
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        if (clothes[i] >= 1)
            answer++;
    }

    return answer;
}
