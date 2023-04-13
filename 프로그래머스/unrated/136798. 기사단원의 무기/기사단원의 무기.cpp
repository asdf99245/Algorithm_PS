#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int number, int limit, int power) {
    int answer = 0;
    vector<int> v(number + 1, 0);
    
    for(int i = 1; i <= number; i++) {
        int cnt = 0;
        for(int j = 1; j * j <= i; j++) {
            if(i % j != 0) continue; 
            
            if(j * j == i) cnt++;
            else cnt += 2;
        }
        v[i] = cnt;
    }
    
    for(int i = 1; i <= number; i++) {
        answer += v[i] <= limit ? v[i] : power;
    }
    
    return answer;
}