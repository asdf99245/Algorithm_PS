function solution(left, right) {
    let answer = 0;
    
    for(let i = left; i <= right; i++){
        let cnt = 0;
        for(let j = 1; j * j <= i; j++) {
            if(j * j === i) cnt++;
            else if(i % j === 0) cnt += 2;
        }
        answer += cnt % 2 === 0 ? i : -1 * i;
    }
    
    return answer;
}