v_vod = input()
players = list(v_vod)
i = 0
znach = 1
znach_1 = 0
players_kolvo = len(players) - 1
while i <= players_kolvo:
    if players[i] == players[i - 1]:
        znach += 1
    else:
        znach = 1
    if znach == 7:
        print("Yes")
        znach_1 = 1
        break
    i += 1
if znach_1 == 0:
    print("No")