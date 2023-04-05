function solution(s, n) {
    let answer = '';
    
    answer = [...s].map((c) => {
        if(c === ' ') return c;
        
        let jump = c.charCodeAt() + n;
        if(c.toLowerCase() === c && jump > 122) {
            jump -= 26;
        }
        else if(c.toUpperCase() === c && jump > 90) {
            jump -= 26;
        }
        return String.fromCharCode(jump);
    }).join('');
    
    return answer;
}