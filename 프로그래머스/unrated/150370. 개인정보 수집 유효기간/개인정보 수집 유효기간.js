const transToDays = (date) => {
    const [year, month, day] = date.split('.').map((n) => parseInt(n));
    
    return day + month * 28 + year * 28 * 12;
}

function solution(today, terms, privacies) {
    const answer = [];
    const map = {}
    
    for(const term of terms) {
        const [type, num] = term.split(' ');
        map[type] = parseInt(num);
    }
    
    const todayDays = transToDays(today);
    
    for(const [idx, pv] of privacies.entries()) {
        const [date, type] = pv.split(' ');
        
        const deadlineDays = transToDays(date) + map[type] * 28;
        
        if(deadlineDays > todayDays) continue;
        answer.push(idx + 1);
    }
    
    return answer;
}