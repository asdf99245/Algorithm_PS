function solution(numbers) {
    return Array.from({length: 10}, (_, i) => i).filter((num) => !numbers.includes(num)).reduce((acc, curr) => acc + curr, 0);
}