def solve():
    
    #Get input:
    players = input()
    
    #Base case:
    if len(players) < 7:
        print("NO")
        return
    
    #Sliding window:
    for i in range(7, len(players)+1):
        player_sub = players[i-7:i]
        player_sum = 0
        for player in player_sub:
            player_sum += int(player)
        if player_sum == 0 or player_sum == 7:
            print("YES")
            return
    print("NO")
    return

solve()