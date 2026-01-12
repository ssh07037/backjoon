#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    //행렬에서 직사각형 모양의 범위를 여러번 선택 , 테두리 부분 숫자들을 시계방향으로 회전
  vector<vector<int>> array(rows, vector<int>(columns));

    int count = 1;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = count++;
        }
    }
    

    
    for (const auto& query : queries)
    {
        int startRowIndex = query[0] - 1;
        int endRowIndex   = query[2] - 1;
        int startColIndex = query[1] - 1;
        int endColIndex   = query[3] - 1;

        int temp = array[startRowIndex][startColIndex];
        int minVal = temp;

        // 오른쪽
        for (int col = startColIndex + 1; col <= endColIndex; col++) 
        {
            swap(temp, array[startRowIndex][col]);
            minVal = min(minVal, temp);
        }

        // 아래
        for (int row = startRowIndex + 1; row <= endRowIndex; row++) 
        {
            swap(temp, array[row][endColIndex]);
            minVal = min(minVal, temp);
        }

        // 왼쪽
        for (int col = endColIndex - 1; col >= startColIndex; col--) 
        {
            swap(temp, array[endRowIndex][col]);
            minVal = min(minVal, temp);
        }

        // 위로
        for (int row = endRowIndex - 1; row >= startRowIndex; row--) 
        {
            swap(temp, array[row][startColIndex]);
            minVal = min(minVal, temp);
        } 
        

        answer.push_back(minVal);
    }
    
    return answer;
}