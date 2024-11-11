players = input()

ok = True
i = 0
while ok and i < len(players) - 7:
    j = i + 1
    while j < len(players) and players[j] == players[i]:
        j += 1
    num_players = j - i
    if num_players >= 7:
        ok = False

    i = j

if ok:
    print('NO')
else:
    print('YES')