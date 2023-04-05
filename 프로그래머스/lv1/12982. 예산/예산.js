function solution(d, budget) {
    let answer = 0;
    
    d.sort((a, b) => a - b);
    for(const m of d) {
        budget -= m;
        if(budget < 0) break;
        
        answer++;
    }
    
    return answer;
}