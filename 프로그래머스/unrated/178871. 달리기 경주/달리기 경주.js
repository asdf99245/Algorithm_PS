function solution(players, callings) {
    const answer = [];
    const playerToRank = new Map();
    const rankToPlayer = new Map();
    
    for(let i = 0; i < players.length; i++) {
        playerToRank.set(players[i], i + 1)
        rankToPlayer.set(i + 1, players[i]);
    }
    
    for(const name of callings) {
        const rank = playerToRank.get(name);
        playerToRank.set(name, rank - 1);
        
        const frontPlayer = rankToPlayer.get(rank - 1);
        playerToRank.set(frontPlayer, playerToRank.get(frontPlayer) + 1);
        
        rankToPlayer.set(rank - 1, name);
        rankToPlayer.set(rank, frontPlayer);
    }
    
    for(const [key, value] of rankToPlayer) {
        answer.push(value);
    }
    
    return answer;
}