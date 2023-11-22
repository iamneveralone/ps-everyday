#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> v1, vector<int> v2){
    return v1[1] < v2[1];
}

int solution(vector<vector<int>> targets) {
    int ans = 0, end = -1;
    
    sort(targets.begin(), targets.end(), cmp);
    
    for (auto t : targets){
        int cur_start = t[0];
        int cur_end = t[1];
        
        if (end <= cur_start){
            ans++;
            end = cur_end;
        }
    }
    return ans;
}