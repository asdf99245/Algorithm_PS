#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    deque<int> dq(B.begin(), B.end());
    
    sort(A.begin(), A.end());
    sort(dq.begin(), dq.end());
    
    if(dq.back() <= A[0]) return 0;
    
    while(!A.empty()) {
        if(A[A.size() - 1] >= dq.back()) {
            dq.pop_front();
        }else {
            dq.pop_back();
            answer++;
        }
        A.pop_back();
    }
    
    return answer;
}