function solution(survey, choices) {
    let answer = '';
    const scoreSum = { A:0, N:0, J:0, M:0, C:0, F:0, R:0, T:0 };
    const score = [, 3, 2, 1, , 1, 2, 3];
    
    for(let i = 0; i < survey.length; i++) {
        const [first, second] = survey[i];
        if(choices[i] === 4) continue;
        
        if(choices[i] >= 4) {
            scoreSum[first] += score[choices[i]];
        }
        else {
            scoreSum[second] += score[choices[i]];
        }
    }
    
    answer += scoreSum['R'] <= scoreSum['T'] ? 'R' : 'T';
    answer += scoreSum['C'] <= scoreSum['F'] ? 'C' : 'F';
    answer += scoreSum['J'] <= scoreSum['M'] ? 'J' : 'M';
    answer += scoreSum['A'] <= scoreSum['N'] ? 'A' : 'N';
    
    return answer;
}