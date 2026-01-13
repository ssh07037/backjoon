#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {

    //col을 기준으로 정렬
    //row begin에서부터 rowend에 해당하는 값들을 xor해서 더한값 출력
    
    int answer = 0;

    int index = col-1;
    
    sort(data.begin(), data.end(), [index](const vector<int>& a, const vector<int>& b) {
    if (a[index] == b[index])
        return a[0] > b[0];   // 기본키 내림차순
    return a[index] < b[index]; // col 오름차순
});
    //solution([[1, 2, 3, 4], [1, 0, 1, 0], [0, 1, 0, 1], [7, 7, 7, 7]], 2, 2, 3)

    
    for(int i=row_begin-1; i<row_end; i++)
    {
        int sum = 0;
        for (int j=0; j<data[0].size(); j++)
        {
            sum += data[i][j] % (i+1);
           // cout << data[i][j] <<" 값과 " << i+1 <<"을 mod 함 " <<  data[i][j] % i+1 << endl;
        }
        answer = answer ^ sum;
    }
    

    
    return answer;
}