function solution(babbling) {
    let answer = 0;
    
    const re = new RegExp(/^(aya|ye|woo|ma)+$/);
    const db = new RegExp(/(ayaaya|yeye|woowoo|mama)/g);
    
    for(const word of babbling) {
        if(word.match(db)) continue;
        if(word.match(re)) {
             answer++;
        }
    }
    
    return answer;
}