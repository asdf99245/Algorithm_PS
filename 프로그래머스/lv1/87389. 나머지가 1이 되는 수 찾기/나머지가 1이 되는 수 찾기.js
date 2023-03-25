function solution(n) {
    let answer = 0;
    for(let i = 2; i <= Math.sqrt(n); i++) {
        if((n - 1) % i === 0) return i;
    }
    if(!answer) answer = n - 1;
    return answer;
}