function solution(n, s) {
    let answer;
    
    const unit = Math.floor(s / n);
    let rest = s % n;
    
    if(unit === 0) return [-1];
    
    answer = new Array(n).fill(unit);
    
    let flag = true;
    while(rest > 0 && flag) {
        for(let i = 0; i < answer.length; i++) {
            answer[i] ++;
            rest--;
            
            if(rest === 0) {
                flag = false;
                break;
            }
        }
    }
    
    answer.sort((a, b) => a - b);
    return answer;
}