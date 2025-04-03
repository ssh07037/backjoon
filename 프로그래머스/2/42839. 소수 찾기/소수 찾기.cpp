#include <string>
#include <vector>
#include<iostream>
#include <string>
#include <set>

using namespace std;
vector<int>sosu(10000000 ,0);
vector<int>number;
set<int> s;
void start(int count , vector<bool>used , string numbers)
{
    if(count == numbers.size()) //number = 1 , 7
    {
        int ans = 0;
        for(int i=0; i<numbers.size(); i++)
        {
           ans = ans * 10 + number[i];
           // cout << ans << endl;
           if(sosu[ans] == 0) //소수면
           {
               s.insert(ans);
           }
            
        }
        //cout << "--------" << endl;
        return;
    }
    for(int i=0; i<numbers.size(); i++)  //[0],0[1],01[2] 포문끝 -> [0],0[2],02[1]
    {
        if(used[i] == false) //중복방지
        {
            number[count] = numbers[i]-'0'; //number[0] = 1  number[1] = 7 
            used[i] = true;             //used[0] = true , used[1] = true
            count++;
            start(count,used,numbers); //
            used[i] = false; //포문이 다 진행되고 뒤로갈 때 반납
            count--;
        }  
    }
}
//0 - 1 - 2
//0 - 1
//0 - 2 - 1
int solution(string numbers) {
    number.resize(numbers.size(), -1);
    vector<bool>used(numbers.size(),false);

    int answer = 0;
    sosu[0] = 1;
    sosu[1] = 1;
    for(int i=2; i<=10000000; i++)
    {
        for(int j=i*2; j<=10000000; j=j+i)
        {
            sosu[j] = 1;
        }
    }
    start(0 , used, numbers);
    answer = s.size();
    //cout << sosu[7] << endl;
    //sosu 백터에 소수인 숫자만 1 적용
    
    return answer;
}