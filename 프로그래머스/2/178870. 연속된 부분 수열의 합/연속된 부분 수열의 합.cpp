#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0;
    int end = 0;
    int sum = sequence[0]; //1
    int minindex= 0;
    pair<int,int>p = make_pair(0,sequence.size()-1);
    int size = sequence.size();
    //end값이 커지는 경우는 sum값이 k값보다 적거나 sum값이 k값을 만족해서 전진하는경우기에 
    //end값이 sequence의 끝에 닿았을 경우엔 이미 더 적은걸 충족하거나 닿았을 때 충족됨
    //그니까 while의 조건문으로 넣는다
    while(end < sequence.size())
    {
        if(sum < k) //1 < 7
        {
            end++;
            sum += sequence[end];
        }
        else if(sum > k)
        {
            sum -= sequence[start];
            start++;
        }
        else if(sum == k)
        {
            if(end - start < size)
            {
                
                answer = {start,end};
                size = end - start;
            }
            end++;
            sum += sequence[end];
        }
    }
    
    return answer;
}