function solution(n) {
    let answer = "수박".repeat(parseInt(n / 2));
    if(n % 2 === 1) answer += "수";
    return answer;
}