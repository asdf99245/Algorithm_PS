function solution(wallpaper) {
    const h = wallpaper.length;
    const w = wallpaper[0].length;
    let minTop = h - 1, minLeft = w - 1, minBottom = 0, minRight = 0;
    
    for(let i = 0; i < h; i++) {
        for(let j = 0; j < w; j++) {
            if(wallpaper[i][j] != '#') continue;
            
            if(i < minTop) minTop = i;
            if(i > minBottom) minBottom = i;
            if(j < minLeft) minLeft = j;
            if(j > minRight) minRight = j;
        }
    }
    
    return [minTop, minLeft, minBottom + 1, minRight + 1];
}