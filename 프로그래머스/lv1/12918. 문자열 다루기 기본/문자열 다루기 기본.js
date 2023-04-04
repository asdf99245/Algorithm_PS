function solution(s) {
    if(s.length !== 4 && s.length !== 6) return false;
    if(s.includes('e')) return false;
    return !isNaN(s);
    
}