#include <string>
#include <vector>
#include <memory.h>
#include <iostream>
#include <algorithm>

using namespace std;

int arr[501][501][4];
int dy[] = {1, 0, -1, 0};
int dx[] = {0, 1, 0, -1};

int nextDir(int dir, char mark) {
    switch(mark) {
        case 'S':
            return dir;
        case 'L':
            return (dir + 1) % 4;
        case 'R':
            return (dir - 1) < 0 ? 3 : dir - 1;
    }
}

pair<int, int> move(int y, int x, int dir, int h, int w) {
    y = y + dy[dir];
    x = x + dx[dir];
    if(y < 0) y = h - 1;
    if(y >= h) y = 0;
    if(x < 0) x = w - 1;
    if(x >= w) x = 0;
    
    return {y, x};
}

int getCycleLength(int y, int x, int dir, vector<string> grid, int h, int w) {
    int currY = y;
    int currX = x;
    int startDir = dir;
    
    int len = 0;
    do {
        arr[currY][currX][dir] = 1;
        dir = nextDir(dir, grid[currY][currX]);
        pair<int,int> next = move(currY, currX, dir, h, w);
        currY = next.first;
        currX = next.second;
        len++;  
    }while(currY != y || currX != x || dir != startDir);

    return len;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer;
    
    memset(arr, -1, sizeof(arr));
    
    int h = grid.size();
    int w = grid[0].size();
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            for(int k = 0; k < 4; k++) {
                if(arr[i][j][k] == 1) continue;
                answer.push_back(getCycleLength(i, j, k, grid, h, w));
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    return answer;
}