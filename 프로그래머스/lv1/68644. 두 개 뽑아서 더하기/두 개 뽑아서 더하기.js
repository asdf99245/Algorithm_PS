function solution(numbers) {
    const set = new Set();
    
    function solution(idx, sum, cnt) {
        if(cnt === 2) {
            set.add(sum);
            return;
        }
        
        for(let i = idx; i < numbers.length; i++) {
            solution(i + 1, sum + numbers[i], cnt + 1);
        }
    }
    
    solution(0, 0, 0);
    
    return [...set].sort((a, b) => a - b);
}