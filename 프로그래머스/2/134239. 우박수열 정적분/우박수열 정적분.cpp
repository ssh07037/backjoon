#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<double>points;
    int lastK = 0;
    float tempPoint = 0;
    int count = 0;
    //x범위가 주어졌을때 [a,b]
    //이 범위의 정적분 결과는 
    while(k != 1)
    {
        if(count != 0)
        {
            tempPoint = (k + lastK )/ 2.0;
             cout << tempPoint << endl;
             cout << count <<"번째 " <<"라스트k값 : "<< lastK << " k값 : " << k << endl;
            points.push_back(tempPoint);
            //cout << tempPoint << endl;
            lastK = k;
        }
       lastK = k;
        
        if(k % 2 == 1)
        {
            k = k * 3 + 1;
        }
        else
        {
            k = k/2;
        }
        count++;
    }
    
    tempPoint = (k + lastK )/ 2.0;
    cout << tempPoint << endl;
    cout << count <<"번째 " <<"라스트k값 : "<< lastK << " k값 : " << k << endl;
    points.push_back(tempPoint);
    lastK = k;
    
    
    for(auto r : ranges)
    {
        double sum = 0;
        int leftIndex = r[0];
        int rightIndex = r[1];
        
        if(leftIndex == 0 && rightIndex == 0)
        {
            for(auto p : points)
            {
               sum += p;
            }            
        }
        else if(leftIndex > rightIndex) //앞이 더 큼 (뒤가 마이너스)
        {
            rightIndex = count + rightIndex;
            if(leftIndex > rightIndex)
            {
                sum = -1;
            }
            else
            {
                for(int i= leftIndex; i < rightIndex; i++)
                {
                    sum += points[i];
                }
            }
        }
        else if(leftIndex < rightIndex)
        {
            for(int i= rightIndex; i < leftIndex; i++)
            {
               sum += points[i];
            }
        }
        
        
        
        answer.push_back(sum);
    }
    return answer;
}