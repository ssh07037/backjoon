#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
map<int,int>count;



void app(int rowsize,int colsize,int startrow,int startcol,vector<vector<int>> &arr){ //참조로 보내는것만으로도 메모리가 엄청 줄어듬
    int zero = 0;
    int one = 0;
    //cout << "행 " <<startrow <<" "  <<rowsize+startrow-1 << "까지" << " 열 " <<startcol << " " << colsize+startcol-1 <<"까지" << endl;
    for(int i=startrow; i<rowsize+startrow; i++) //0~2
    {
        for(int j=startcol; j<colsize+startcol; j++)
        {
            if(arr[i][j] == 0)
            {
                zero++;
            }
            else if(arr[i][j] == 1)
            {
                one++;
            }
            //cout << i <<"행 " << j << "열 " << endl;
        }
    }
    if(zero == colsize * rowsize)
    {
        count[0]++;
        return;
    }
    else if(one == colsize * rowsize)
    {
        count[1]++;
        return;
    }
    else
    {
        //cout << zero << "제로갯수 " << one << "원갯수" << endl;
        app(rowsize/2,colsize/2,startrow,startcol,arr); //0,0
        app(rowsize/2,colsize/2,startrow,startcol+colsize/2,arr); //0,1
        app(rowsize/2,colsize/2,startrow+rowsize/2,startcol,arr);
        app(rowsize/2,colsize/2,startrow+rowsize/2,startcol+colsize/2,arr);

    }
    
}
vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    //압축을 원하는 지역 s
    //s내부의 수가 모두 같은 값이면 s를 하나로 압축
    //그렇지 않으면 다시 4개로 쪼갬
    //최종적으로 남는 0과 1의 갯수 리턴
    
    
    if(arr.size() == 1) //2x2까지 예외처리
    {
        
        answer.push_back(arr[0][0]);
        return answer;
    }
    
    app(arr.size(), arr.size(), 0, 0, arr);

    
    answer.push_back(count[0]);
    answer.push_back(count[1]);
    return answer;
}