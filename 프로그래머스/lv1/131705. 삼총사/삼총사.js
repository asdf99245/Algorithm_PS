function solution(number) {
    let answer = 0;
    
    function solution(curr, sum, cnt) {
        if(cnt === 3) {
            if(sum === 0) answer++;
            return;
        }
        
        for(let i = curr; i < number.length; i++) {
            solution(i + 1, sum + number[i], cnt + 1);   
        }
    }
    solution(0, 0, 0);
    
    return answer;
}