#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> score;
    
    for(int i = 0; i < name.size(); i++) {
        score[name[i]] = yearning[i];
    }
    
    for(auto names: photo) {
        int sum = 0;
        for(auto name: names) {
            if(!score[name]) continue;
            sum += score[name];
        }
        answer.push_back(sum);
    }
    
    return answer;
}