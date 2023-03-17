function solution(cap, n, deliveries, pickups) {
    let answer = 0;
    
    const dStack = [];
    const pStack = [];
    
    for(let i = 0; i < n; i++) {
        if(deliveries[i]) dStack.push([i + 1, deliveries[i]]);
        if(pickups[i]) pStack.push([i + 1, pickups[i]]);
    }
    
    while(dStack.length > 0 || pStack.length > 0) {
        const dEnd = dStack.length > 0 ? dStack[dStack.length - 1][0] : 0;
        const pEnd = pStack.length > 0 ? pStack[pStack.length - 1][0] : 0;
        answer += Math.max(dEnd, pEnd);
        
        let dCap = cap;
        while(dCap > 0 && dStack.length > 0) {
            if(dStack[dStack.length - 1][1] <= dCap) {
                dCap -= dStack[dStack.length - 1][1];
                dStack.pop();
            }
            else { 
                dStack[dStack.length - 1][1] -= dCap;
                break;
            }
        }
        
        let pCap = cap;
        while(pCap > 0 && pStack.length > 0) {
            if(pStack[pStack.length - 1][1] <= pCap) {
                pCap -= pStack[pStack.length - 1][1];
                pStack.pop();
            }
            else {
                pStack[pStack.length - 1][1] -= pCap;
                break;
            }
        }
    }
    
    return answer * 2;
}