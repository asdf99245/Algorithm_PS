function solution(n) {
    let answer = -1;
    const sqrt = Math.sqrt(n);
    if(Number.isInteger(sqrt)) answer = (sqrt + 1) ** 2;
    return answer;
}