function solution(n) {
    let answer = 0;
    
    const nums = new Array(n + 1).fill(true);
    for(let i = 2; i <= n; i++){
        if(!nums[i]) continue;
        for(let j = i + i; j <= n; j+=i){
            nums[j] = false;
        }
    }

    for(let i = 2; i <= n; i++) {
        if(!nums[i]) continue;
        answer++;
    }
    
    return answer;
}