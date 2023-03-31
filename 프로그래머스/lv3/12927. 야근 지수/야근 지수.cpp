#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    long long sum = 0;
    for(auto work: works) {
        sum += work;
        pq.push(work);
    }
    
    if(n >= sum) return 0;
    
    while(n > 0){
        int mw = pq.top();
        pq.pop();
        pq.push(mw - 1);
        n--;
    }
    
    while(!pq.empty()) {
        int w = pq.top();
        answer += w * w;
        pq.pop();
    }
    
    return answer;
}