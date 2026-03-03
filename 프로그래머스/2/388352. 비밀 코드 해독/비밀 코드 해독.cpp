#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;
int z = 0;
void makeCode(int num,vector<int>&temp,int n,vector<vector<int>>& q, vector<int>& ans)
{
    if(temp.size() == 5)
    {
        bool check = true;
        int row = 0;
        for(int i=0; i<q.size(); i++) //조건 q를 돈다
        {
            int count = 0;
            for(int j=0; j<5; j++) //각 q의 첫~마지막값을 돈다
            {
                for(int k=0; k<5; k++)
                {
                    //1 1 1 2 12   1 4 6 7 9 //1이 3개있기에 3이나와야함
                    if(temp[k] == q[i][j])
                    {
                        count++;
                    }
                }
                row = i;
            }
            if(count != ans[i])
            {
                
                check = false;
                break;
            }
        }
        if(check == true)
        {
             //cout<< temp[0] <<" "<<temp[1]<<" "<<temp[2]<<" "<<temp[3]<<" "<<temp[4]<<" " << endl;
            z++;
        }
        return;
    }
        
    for (int i = num; i <= n; i++)
    {
        temp.push_back(i);
        makeCode(i+1,temp,n,q,ans); 
        temp.pop_back();
    }
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
    int answer = 0;
    vector<int>temp;
    vector<int>temp2 = {3,4,7,9,10};
    makeCode(1,temp,n,q,ans);
   // makeCode2(temp2,n,q,ans);
    
    cout << z << endl;
    return answer = z;
}