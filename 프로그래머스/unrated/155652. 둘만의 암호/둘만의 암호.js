function solution(s, skip, index) {
    let answer = '';
    let alphabets = '';
    
    for(let i = 97; i <= 122; i++) {
        const c = String.fromCharCode(i);
        if(skip.indexOf(c) !== -1) continue;
        alphabets += c;
    }
    
    for(let i = 0; i < s.length; i++) {
        const idx = (alphabets.indexOf(s[i]) + index) % alphabets.length;
        
        answer += alphabets[idx];
    }
    return answer;
}