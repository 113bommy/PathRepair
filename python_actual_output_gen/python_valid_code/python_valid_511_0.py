def compare(i, j, ranks):
    i_win = 0
    for race in range(5):
        if ranks[i][race] < ranks[j][race]:
            i_win += 1
            
    if i_win >= 3:
        return i
    else:
        return j

for _ in range(int(input())):
    n = int(input())
    ranks = []
    for _ in range(n):
        ranks.append(list(map(int, input().split())))

    current_winner = 0
    for i in range(1, n):
        current_winner = compare(current_winner, i, ranks)
        
    for i in range(1, n):
        if i != current_winner:
            if compare(current_winner, i, ranks) != current_winner:
                print(-1)
                break
        
    else:
        print(current_winner + 1)    