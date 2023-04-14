function solution(keymap, targets) {
    const answer = [];
    
    for(const target of targets) {
        let cnt = 0;
        for(const c of target) {
            const min = Math.min(...keymap.map((key) => key.indexOf(c)).filter((i) => i != -1));
            if(min === Infinity) {
                cnt = -1;
                break;
            }
            cnt += min + 1;
        }
        answer.push(cnt);
    }
    
    return answer;
}