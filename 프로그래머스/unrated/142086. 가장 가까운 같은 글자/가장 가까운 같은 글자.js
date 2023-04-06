function solution(s) {
    const answer = [];
    const map = new Map();
    
    for(let i = 0; i < s.length; i++){
        if(map.has(s[i])) {
            answer.push(i - map.get(s[i]));
            map.set(s[i], i);
            continue;
        }   
        map.set(s[i], i);
        answer.push(-1);
    }
    
    return answer;
}