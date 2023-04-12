#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int day = 0;
    while(day < k && day < score.size()) {
        pq.push(score[day++]);
        answer.push_back(pq.top());
    }
    
    for(int i = day; i < score.size(); i++) {
        if(pq.top() < score[i]) {
            pq.push(score[i]);
            pq.pop();
        }
            
        answer.push_back(pq.top());
    }
    
    return answer;
}