#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

bool compare(char i, char j) {
    return j < i;
} 

string solution(string X, string Y) {
    string answer = "";
    map<char, int> mp;
    
    for(auto c: X) {
        mp[c]++;
    }
    
    for(auto c: Y) {
        if(mp[c]) {
            answer += c;
            mp[c]--;
        }
    }
    
    sort(answer.begin(), answer.end(), compare);
    
    if(!answer.size()) return "-1";
    
    if(answer[0] == '0') return "0";
    
    return answer;
}