#include <vector>

using namespace std;

int max_diff = 0; //최대 점수차이
vector<int> result = {-1}; //결과값

void dfs(int n, const vector<int>& info, vector<int>& info2, int index) {
    if (index == 11) 
    { 
        int apeach_score = 0;
        int rion_score = 0;
        
        for(int i = 0; i < 11; i++) 
        {
            if (info[i] == 0 && info2[i] == 0) 
                continue; 
            if (info[i] < info2[i]) 
                rion_score += 10 - i;
            else 
                apeach_score += 10 - i;
        }
        
        int current_diff = rion_score - apeach_score;
        
        if (current_diff > 0) 
        { // 라이언이 이긴 경우만
            if (current_diff > max_diff) 
            {
                max_diff = current_diff;
                result = info2;
            } 
            else if (current_diff == max_diff) 
            {
                // 점수 차가 같다면 낮은 점수를 더 많이 맞힌 것 선택
                for (int i = 10; i >= 0; i--) 
                {
                    if (info2[i] > result[i]) 
                    {
                        result = info2;
                        break;
                    } 
                    else if (info2[i] < result[i]) 
                    {
                        break;
                    }
                }
            }
        }
        return;
    }

    // 10점~1점까지는 기존 로직 유지, 0점(마지막)에서 남은 화살 처리
    if (index == 10) 
    {
        info2[10] = n;
        dfs(0, info, info2, index + 1);
        info2[10] = 0;
    } 
    else 
    {
        int target_arrow = info[index] + 1;
        if (n >= target_arrow) 
        {
            info2[index] = target_arrow;
            dfs(n - target_arrow, info, info2, index + 1);
            info2[index] = 0;
        }
        dfs(n, info, info2, index + 1);
    }
}

vector<int> solution(int n, vector<int> info) 
{
    max_diff = 0;
    result = {-1};
    
    vector<int> info2(11, 0);
    dfs(n, info, info2, 0);
    
    return result;
}