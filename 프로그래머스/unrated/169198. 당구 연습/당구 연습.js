function solution(m, n, startX, startY, balls) {
    const answer = [];
    
    for(const [x, y] of balls) {
        let len;
        if(x === startX) {
            len = (y - startY) ** 2 + (2 * (x > m / 2 ?  m - x : x)) ** 2;
            const horizonMove = (Math.abs(y - startY) + 2 * (y < startY ? n - startY : startY)) ** 2;
            len = Math.min(len, horizonMove);
        }else if(y === startY) {
            len = (x - startX) ** 2 + (2 * (y > n / 2 ?  n - y : y)) ** 2;
            const verticalMove = (Math.abs(x - startX) + 2 * (x < startX ? m - startX : startX)) ** 2;
            len = Math.min(len, verticalMove);
        }else {
            const lens = []
            lens.push((-x - startX) ** 2 + (y - startY) ** 2);
            lens.push((x - startX) ** 2 + (-y - startY) ** 2);
            lens.push((x - startX) ** 2 + (2 * n - y - startY) ** 2);
            lens.push((2 * m - x - startX) ** 2 + (y - startY) ** 2);
            
            len = Math.min(...lens);
        }
        answer.push(len);
    }
    
    return answer;
}