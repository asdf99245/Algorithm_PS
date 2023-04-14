#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;
    
    for(int i = 0; i < ingredient.size(); i++) {
        if(v.size() >= 3 && ingredient[i] == 1) {
            int lastIdx = v.size() - 1;
            if(v[lastIdx - 2] == 1 && v[lastIdx - 1] == 2 && v[lastIdx] == 3) {
                v.pop_back();
                v.pop_back();
                v.pop_back();
                answer++;
                continue;
            }
        }
        v.push_back(ingredient[i]);
    }
    
    return answer;
}