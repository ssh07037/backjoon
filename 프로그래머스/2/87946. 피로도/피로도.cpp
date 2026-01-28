#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool check[5000];
int count;
int count_max;
void dfs(int k , const vector<vector<int>>& dungeons)
{
    for(int i=0; i<dungeons.size(); i++)
    {
        bool pass = false;
        if(check[i] == true)
        {
            continue;
        }
        check[i] = true;
        if(k >= dungeons[i][0]) //조건만족시
        {
            pass = true;
            check[i] = true;
            //cout << k << "현재 피로도 " << dungeons[i][0] << "조건만족" << endl;
            k -= dungeons[i][1]; //피로도감소
            count++;
            //cout << k << "    계산 피로도 " << k << "카운트" << count << endl;;
            if(count_max < count)
            {
                count_max = count;
            }  
        }
        dfs(k,dungeons);
        //-------------
        if(pass == true)
        {
            k +=dungeons[i][1];
            count--;
        }
        check[i] = false;
    }
    
}
int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    //0 = 최소피로도 , 1= 소모피로도
    //배열이 주어졌을때 가장 많이 돌 수 있는 수를 리턴
    
    //만약에 정렬을 했는데 최소피로도는 100 근데 소모피로도가 200 막 이래서 그 뒤에 진짜 최소에 소모피로도 적은던전을 돌 수 없을수도\
    //인간적 사고론 지금 돌 수 있는 던전중에서 찾긴하는데
    
    dfs(k,dungeons);
    answer =count_max;
    return answer;
}