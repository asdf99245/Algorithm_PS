function solution(t, p) {
    let answer = 0;
    
    const nump = Number(p);
    const tlen = t.length;
    const plen = p.length;
    
    for(let i = 0; i < tlen - plen + 1; i++) {
        if(nump >= Number(t.slice(i, i + plen))) answer++;
    }
    return answer;
}