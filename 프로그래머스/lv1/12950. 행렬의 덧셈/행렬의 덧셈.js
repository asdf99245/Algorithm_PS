function solution(arr1, arr2) {
    return arr1.reduce((acc, curr, idx) => {      
        acc.push(curr.map((item, i) => item + arr2[idx][i]));
        return acc;
    }, []);
}