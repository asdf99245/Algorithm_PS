function solution(s) {
    let answer = 0;
    
    let idx = 0;
    while(idx < s.length) {
        const x = s[idx++];
        let cntX = 1, cntOther = 0;
        while(cntX != cntOther) {
            if(x === s[idx++]) cntX++;
            else cntOther++;
        }
        
        answer++;
    }
    
    return answer;
}