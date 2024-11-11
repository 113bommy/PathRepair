def main():
    s = input().split()
    n = int(s[0])
    m = int(s[1])
    k = int(s[-1])
    players = []
    for i in range(m):
        player = int(input())
        players.append(player)
    fedor = int(input())
    army = []
    for i in range(n-1):
        army.append(fedor%2)
        fedor = fedor // 2
    output = 0
    for i in range(m):
        dif = 0
        j = 0
        t = 0
        while j < len(army) and t<n:
            if players[i] % 2 != army[j]:
                dif += 1
            j += 1
            players[i] = players[i] //2
            t += 1
        if dif <= k:
            output += 1
    print(output)
            
main()
