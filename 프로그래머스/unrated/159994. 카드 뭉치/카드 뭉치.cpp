#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "Yes";
    
    reverse(cards1.begin(), cards1.end());
    reverse(cards2.begin(), cards2.end());
    reverse(goal.begin(), goal.end());
    
    while(!goal.empty()) {
        if(cards1.back() != goal.back() && cards2.back() != goal.back()) {
            answer = "No";
            break;
        }
        
        if(cards1.back() == goal.back()) {
            cards1.pop_back();
        }
        
        if(cards2.back() == goal.back()) {
            cards2.pop_back();
        }
        
        goal.pop_back();
    }
    
    return answer;
}