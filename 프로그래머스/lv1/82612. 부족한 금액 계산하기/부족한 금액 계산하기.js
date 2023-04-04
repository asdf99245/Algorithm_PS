function solution(price, money, count) {
    let sum = 0;
    
    for(let i = 0; i < count; i++) {
        sum += (i + 1) * price;
    }
    
    return sum - money <= 0 ? 0 : sum - money;
}