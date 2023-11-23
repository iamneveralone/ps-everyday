#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 1. 합이 k인 수열
// 2. 그 중에서 길이가 짤은 수열
// 3. 그 중에서 시작 인덱스가 작은 수열

vector<int> solution(vector<int> sequence, int k) {
    vector<int> ans;
    int start = -1, end = -1;
    int sum = 0, len = 0, seqlen = sequence.size();
    
    while (start <= end && end < seqlen) {
		if (sum == k) {
			if (ans.size() == 0 || end - start < len) {
				ans = { start + 1, end };
				len = end - start;
			}
            end++;
            sum += sequence[end];
		}
		else if (sum < k) {
			end++;
			sum += sequence[end];
		}
		else if (sum > k) {
			start++;
			sum -= sequence[start];
		}
	}
  return ans;
}