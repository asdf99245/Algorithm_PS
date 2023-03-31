#include <iostream>
#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    
    vector<pair<int,int>> section;
    
    int left = 0;
    for(auto st: stations) {
        int idx = st - 1;
        
        if(idx - w <= 0) {
            if(idx + w >= n) {
                return 0;
            }
        }
        else {
            if(left <= idx - w - 1) 
                section.push_back({left, idx - w - 1});
        }
        
        left = idx + w + 1;
    }
    
    if(left < n) {
        section.push_back({left, n - 1});
    }
    
    for(auto sec : section) {
        int start = sec.first;
        int end = sec.second;
        
        int sectionSize = end - start + 1;
        int range = 2 * w + 1;
        
        if(sectionSize <= range) {
            answer++;
        }else {
            answer += ceil((float)sectionSize / range);
        }
    }

    return answer;
}