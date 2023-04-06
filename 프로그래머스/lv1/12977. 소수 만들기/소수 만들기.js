function solution(nums) {
    let answer = 0;
    
    nums.sort((a, b) => b - a);
    const maxNum = nums[0] + nums[1] + nums[2];
    const primes = new Array(maxNum + 1).fill(true);
    
    for(let i = 2; i <= maxNum; i++) {
        for(let j = i * 2; j <= maxNum; j+=i) {
            primes[j] = false;
        }
    }
    
    function solution(idx, sum, cnt) {
        if(cnt === 3){
            if(primes[sum]) answer++;
            return;
        }
        
        for(let i = idx; i < nums.length; i++){
            solution(i + 1, sum + nums[i], cnt + 1);
        }
    }
    
    solution(0, 0, 0);
    
    return answer;
}