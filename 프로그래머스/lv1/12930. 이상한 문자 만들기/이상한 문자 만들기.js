function solution(s) {
    return s.split(' ').map((word) => [...word].map((c, i) => {
        if(i % 2 === 1) return c.toLowerCase();
        else return c.toUpperCase();
    }).join('')).join(' ');
}