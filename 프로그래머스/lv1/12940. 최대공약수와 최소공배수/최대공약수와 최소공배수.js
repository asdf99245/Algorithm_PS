function solution(n, m) {
    function getGcd(a, b) {
        if(b === 0) return a;
        return getGcd(b, a % b);
    }

    const gcd = getGcd(n, m);
    return [gcd, n * m / gcd];
}