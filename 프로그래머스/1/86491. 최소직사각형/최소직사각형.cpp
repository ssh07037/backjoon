#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> sizes) {
    int maxW = 0;
    int maxH = 0;

    for (auto a : sizes) {
        int w = max(a[0], a[1]);
        int h = min(a[0], a[1]);

        maxW = max(maxW, w);
        maxH = max(maxH, h);
    }

    return maxW * maxH;
}