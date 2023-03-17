function solution(word) {
    let answer = 0;
    const chars = ["A", "E", "I", "O", "U"];
    let dict = [];
    
    function makeDict(str, n) {
        if(n === 0) {
            dict.push(str);
            return;
        }
        
        makeDict(str, n - 1);
        for(const c of chars) {
            makeDict(str + c, n - 1);
        }
    }
    
    makeDict("", 5);
    dict = [...new Set(dict)].sort();
    return answer = dict.indexOf(word);
}