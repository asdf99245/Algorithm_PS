function solution(x) {
    return x % x.toString().split("").reduce((acc, curr) => acc + +curr, 0) === 0;
} 