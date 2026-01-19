#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool compare(const pair<int,int>& a, const pair<int,int>& b)
{
    if (a.first != b.first)
        return a.first > b.first;   // 재생 수 내림차순
    return a.second < b.second;     // 인덱스 오름차순
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    unordered_map<string, vector<pair<int,int>>> mainhash;
    unordered_map<string, int> secondhash;

    for (int i = 0; i < genres.size(); i++)
    {
        mainhash[genres[i]].push_back(make_pair(plays[i], i));
        secondhash[genres[i]] += plays[i];
    }

    // 장르 내부 정렬
    for (auto& a : mainhash)
    {
        sort(a.second.begin(), a.second.end(), compare);
    }

    // 장르 정렬
    vector<pair<string,int>> genresOrder;
    for (auto& a : secondhash)
        genresOrder.push_back(a);

    sort(genresOrder.begin(), genresOrder.end(),
         [](const pair<string,int>& a, const pair<string,int>& b)
         {
             return a.second > b.second;
         });

    // 결과 생성
    for (auto& g : genresOrder) //장르 돌면서
    {
        auto& vec = mainhash[g.first]; //해당 장르의 백터 가져옴
        answer.push_back(vec[0].second); //첫번쨰값 
        if (vec.size() > 1) //2번째값있으면 2번째값까지
            answer.push_back(vec[1].second);
    }

    return answer;
}
