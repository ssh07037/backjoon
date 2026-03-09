#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) 
{
    int row = relation.size();
    int col = relation[0].size();
    
    vector<int> candidate;
    
    for(int mask = 1; mask < (1 << col); mask++)
    {
        // 최소성 검사
        bool minimal = true;
        for(int key : candidate)
        {
            if((key & mask) == key)
            {
                minimal = false;
                break;
            }
        }
        
        if(!minimal) continue;
        
        // 유일성 검사
        set<string> s;
        
        for(int r = 0; r < row; r++)
        {
            string temp = "";
            
            for(int c = 0; c < col; c++)
            {
                if(mask & (1 << c))
                {
                    temp += relation[r][c];
                }
            }
            
            s.insert(temp);
        }
        
        if(s.size() == row)
        {
            candidate.push_back(mask);
        }
    }
    
    return candidate.size();
}