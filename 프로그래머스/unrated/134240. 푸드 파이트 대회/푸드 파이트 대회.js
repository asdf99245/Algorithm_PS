function solution(food) {
    const line = food.reduce((acc, curr, i) => {
        if(i === 0) return acc;
        
        return acc + String(i).repeat(parseInt(curr / 2));
    }, '');
    return `${line}0${[...line].reverse().join('')}`;
}