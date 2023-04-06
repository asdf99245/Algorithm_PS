function solution(sizes) {
    let answer = 0;
    
    sizes.map((size) => size.sort((a, b) => a -b));

    return Math.max(...sizes.map((size) => size[0])) * Math.max(...sizes.map((size) => size[1]));
}