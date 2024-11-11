n = int(input())
players = [1, 2]
specs = [3]
state = "YES"
for i in range(n):
    x = int(input())

    if x not in players:
        state = "NO"
        break

    for j in range(2):
        if players[j] != x:
            e = j

    temp = players.pop(e)
    players.append(specs[0])
    specs.pop()
    specs.append(temp)
    print(players, specs)

print(state)    