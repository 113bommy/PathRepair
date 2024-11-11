t = int(input())
for i in range(t):
    n = int(input())
    players = input()
    list_2 = []
    for j, player in enumerate(players):
        if player == '2':
            list_2.append(j)
    
    if len(list_2) == 1 or len(list_2) == 2:
        print("NO")
    else:
        print("YES")
        games = [["=" for x in range(n)] for x in range(n)]
        for j in range(n):
            games[j][j] = "X"
        for j, two in enumerate(list_2):
            other = j+1
            if j+1 == len(list_2):
                other = 0
            games[two][list_2[other]] = '+'
            games[list_2[other]][two] = '-'
        print("\n".join(["".join(l) for l in games]))