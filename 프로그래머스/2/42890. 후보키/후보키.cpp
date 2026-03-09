#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> relation) {
    int answer = 0;
    int row = relation.size();
    int col = relation[0].size();
    //cout << row << " " << col << endl;
    vector<int>keys;
    for(int mask = 1; mask < (1<<col); mask++)
    {
        bool next = false;
        for(auto a : keys)
        {
            if((mask & a) == a)
            {
                next = true;
                break;
            }
        }
        if(next == true)
            continue;
        
        set<string>s;
        for(int i=0; i<row; i++)
        {
            string temp="";
            for(int j=0; j<col; j++)
            {
                if(mask & (1<<j))
                {
                    temp += relation[i][j];
                }
            }
            //cout << temp << endl;
            s.insert(temp);
        }
        if(s.size() == row)
        {
            keys.push_back(mask);
        }
    }   
    return answer = keys.size();
}