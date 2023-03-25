function solution(s){
    let answer = true;
    
    let p = 0, y = 0;
    s = s.toLowerCase();
    s.split('').forEach((c) => {
        if(c === 'p') p++;
        else if(c === 'y') y++;
    })

    return answer = (p === y);
}