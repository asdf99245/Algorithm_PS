function solution(n, l, r) {
    let answer = 0;
    
    function isOne(n) {
        if(n % 5 === 0) {
            n /= 5;
        }else {
            n = Math.ceil(n / 5);
        }
        
        if(n % 5 === 3) {
            return 0;
        }
        
        if(n <= 5) return 1;
        
        return isOne(n);
    }
    
    for(let i = l; i <= r; i++) {
        if(i % 5 === 3) continue;
        
        answer += isOne(i);
    }
    
    return answer;
}