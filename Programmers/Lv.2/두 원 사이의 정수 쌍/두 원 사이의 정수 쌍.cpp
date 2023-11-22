#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long ans = 0;
    
    for (int x = 1; x <= r1; x++){
        double y1 = sqrt(pow(r1, 2) - pow(x, 2)); // y1^2 = r1^2 - x^2
        double y2 = sqrt(pow(r2, 2) - pow(x, 2)); // y2^2 = r2^2 - x^2
        
        y1 = (long long) ceil(y1); // 올림
        y2 = (long long) floor(y2); // 버림
        
        ans += (y2 - y1 + 1); // 개수 구할 때는 y2 - y1 + 1
    }
    for (int x = r1 + 1; x <= r2; x++){
        double y = sqrt(pow(r2, 2) - pow(x, 2)); // y2^2 = r2^2 - x^2
        
        y = (long long) floor(y); // 버림
        
        ans += (y + 1); // 개수 구할 때는 y + 1
    }
    
    return ans * 4;
}