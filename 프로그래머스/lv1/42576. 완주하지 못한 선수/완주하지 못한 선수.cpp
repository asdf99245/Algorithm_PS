#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> mp;
    
    for(auto name: completion) {
        mp[name]++;
    }
    
    for(auto name: participant) {
        if(!mp[name]) {
            answer = name;
            break;
        }
        
        mp[name]--;
    }
    
    return answer;
}