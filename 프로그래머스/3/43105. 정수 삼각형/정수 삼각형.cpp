#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    for(int i=1; i<triangle.size(); i++)
    {
        int left_value = 0;
        int right_value = 0;
        for(int j=0; j<triangle[i].size(); j++)
        {
            if(j == 0)
            {
                left_value = 0;
                right_value = triangle[i-1][j] + triangle[i][j];
            }
            else if(j == triangle[i].size()-1)
            {
                left_value = triangle[i-1][j-1] + triangle[i][j];
                right_value = 0;
            }
            else
            {
               left_value = triangle[i-1][j-1] + triangle[i][j];
                right_value = triangle[i-1][j] + triangle[i][j];
            }
            triangle[i][j] = max(left_value , right_value);
        }
    }
    
    
    answer = *max_element(triangle[triangle.size() - 1].begin(), triangle[triangle.size() - 1].end());
    return answer;
}