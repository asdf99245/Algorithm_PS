function solution(num) {
    let answer = '';
    answer = Math.abs(num % 2) === 1 ? 'Odd' : 'Even';
    return answer;
}