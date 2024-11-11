nk = input().split()
n = int(nk[0])
k = int(nk[1])
players = [int(i) for i in input().split()]
if k>n:
    print(max(players))
else:
    playing = players[0:2]
    queue = players[2:]
    win = False
    wins = 0
    while wins<k:
        if playing[0]>playing[1]:
            wins+=1
            queue.append(playing[1])
            playing[1] = queue.pop(0)
        else:
            wins=0
            playing[0], playing[1] = playing[1], playing[0]
            queue.append(playing[1])
            playing[1] = queue.pop(0)
    print(playing[0])