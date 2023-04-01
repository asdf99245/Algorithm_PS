function solution(stones, k) {
    let answer = 0;
    
    let start = 1;
    let end = 2e8;
    
    while(start <= end) {
        const mid = Math.floor((start + end) / 2);
        
        let count = 0;
        for(const stone of stones) {
            if(count === k) break;
            
            if(stone - mid > 0) count = 0;
            else count++;
        }
        
        if(count === k) {
            end = mid - 1;
        }else {
            start = mid + 1;
        }
    }
    
    return answer = start;
}