function solution(n) {    
    return answer = (n + '').split('').reduce((acc,curr) => acc + Number(curr), 0);
}