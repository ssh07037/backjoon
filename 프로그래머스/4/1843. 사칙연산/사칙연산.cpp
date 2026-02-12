#include <vector>
#include <string>
#include <climits>
using namespace std;

int solution(vector<string> arr)
{
    int answer = -1;
    vector<int>numbers;
    vector<char>operates;
    
    for(int i=0; i<arr.size(); i++)
    {
        if(i % 2== 0)
        {
            numbers.push_back(stoi(arr[i]));
        }
        else
        {
            operates.push_back(arr[i][0]);
        }
    }
    
    vector<vector<int>> max_numbers(numbers.size(), vector<int>(numbers.size(), INT_MIN));
    vector<vector<int>> min_numbers(numbers.size(), vector<int>(numbers.size(), INT_MAX));
    for(int i=0; i<numbers.size(); i++)
    {
        max_numbers[i][i] = numbers[i];
        min_numbers[i][i] = numbers[i];
    }
    
    for(int length = 2; length <= numbers.size(); length++) //길이
    {
        for(int i = 0;  i+length-1 < numbers.size(); i++) //왼쪽
        {
            int j = i+length-1;
            for(int k = i; k < j; k++)
            {
                if(operates[k] == '+')
                {
                    max_numbers[i][j] = max(max_numbers[i][j] , max_numbers[i][k] + max_numbers[k+1][j]);
                    min_numbers[i][j] = min(min_numbers[i][j], min_numbers[i][k] + min_numbers[k+1][j]);
                }
                else if(operates[k] == '-')
                {
                    max_numbers[i][j] = max(max_numbers[i][j] ,max_numbers[i][k] - min_numbers[k+1][j]);
                    min_numbers[i][j] = min(min_numbers[i][j], min_numbers[i][k] - max_numbers[k+1][j]);
                }
            }
            //[[1],3,5,8]
        }
    }
    answer = max_numbers[0][max_numbers.size()-1];
    return answer;
}