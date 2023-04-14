function solution(park, routes) {
    const dirs = {
        'E': [0, 1],
        'S': [1, 0],
        'N': [-1, 0],
        'W': [0, -1],
    }
    const h = park.length;
    const w = park[0].length;
    
    let currY, currX;
    for(let i = 0; i < h; i++) {
        for(let j = 0; j < w; j++) {
            if(park[i][j] === 'S') {
                [currY, currX] = [i, j];
                break;
            }
        }
    }
    
    for(const route of routes) {
        const [dir, offset] = route.split(' ');
        const [dy, dx] = dirs[dir];
        
        const ny = currY + dy * offset;
        const nx = currX + dx * offset;
        
        if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;

        let flag = false;
        for(let i = 1; i <= offset; i++) {
            if(park[currY + dy * i][currX + dx * i] === 'X') {
                flag = true;
                break;
            }
        }
        
        if(flag) continue;
        
        currY += dy * offset;
        currX += dx * offset;
    }
    
    return [currY, currX];
}