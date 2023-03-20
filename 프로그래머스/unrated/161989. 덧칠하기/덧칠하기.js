function solution(n, m, section) {
    let answer = 0;
    
    if(n <= m || section[section.length - 1] - section[0] + 1 <= m) return 1;
    
    let lastIdx = section[0] - 1;
    for(const s of section) {
        if(s > lastIdx) {
            lastIdx = s + m - 1;
            answer++;
        }
    }
    
    return answer;
}