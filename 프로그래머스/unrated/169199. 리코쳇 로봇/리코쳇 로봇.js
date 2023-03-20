class Queue {
    constructor() {
        this.q = {};
        this.head = 0;
        this.tail = 0;
    }
    
    isEmpty() {
        return this.head === this.tail;
    }
    
    push(item) {
        this.q[this.tail++] = item;
    }
    
    pop() {
        const front = this.q[this.head++];
        return front;
    }
}

function solution(board) {
    let answer = 0;
    const dy = [-1, 1, 0, 0];
    const dx = [0, 0, -1, 1];
    const h = board.length;
    const w = board[0].length;
    
    let startY, startX, endY, endX;
    
    for(let i = 0; i < h; i++) {
        for(let j = 0; j < w; j++) {
            if(board[i][j] === 'R') {
                startY = i;
                startX = j;
            }else if(board[i][j] === 'G'){
                endY = i;
                endX = j;
            }
        }
    }
    
    function isIn(y, x) {
        return 0 <= y && y < h && 0 <= x && x < w;
    }
    
    function play() {
        const visited = Array.from({length: h}, () => new Array(w).fill(false));
        const queue = new Queue();
        
        queue.push([startY, startX, 0]);
        visited[startY][startX] = true;
        
        while(!queue.isEmpty()) {
            const [y, x, cnt] = queue.pop();
            
            if(y === endY && x === endX) {
                return cnt;
            }
            
            for(let i = 0; i < 4; i++) {
                let ny = y;
                let nx = x;
                while(isIn(ny + dy[i], nx + dx[i]) && board[ny + dy[i]][nx + dx[i]] !== 'D') {
                    ny += dy[i];
                    nx += dx[i];
                }
                
                if(visited[ny][nx]) continue;
                queue.push([ny, nx, cnt + 1]);
                visited[ny][nx] = true;
            }
        }
        
        return -1;
    }
    
    return answer = play();
}