#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    
    sort(routes.begin(),routes.end(),[](auto& a , auto& b){
        return a[1] < b[1];
    });
    
   

    
    int min = -30001;
    for(auto a : routes)
    {
        if(min < a[0])
        {
            cout << min << " " << a[0] << endl;
            min = a[1];
            answer++;
        }
    }
    return answer;
}