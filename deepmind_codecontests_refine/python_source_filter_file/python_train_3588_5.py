I   = lambda : input()
IMI = lambda : map(int, input().split())
P   = lambda *l : print(*l)

team1 = I()
team2 = I()
n = int(I())

EVENTS = [list(I().split()) for i in range(n)]

res_team1 = [0] * 100
res_team2 = [0] * 100

res = []
for e in EVENTS:
    if e[1] == 'h':
        if e[3] == 'y':
            if res_team1 != 1:
                res_team1[int(e[2])] += 1
        else:
            if res_team1 != 1:
                res_team1[int(e[2])] += 2
        if res_team1[int(e[2])] >= 2:
            res_team1[int(e[2])] = -100
            print(team1, e[2], e[0])
    else:
        if e[3] == 'y':
            if res_team2 != 1:
                res_team2[int(e[2])] += 1
        else:
            if res_team2 != 1:
                res_team2[int(e[2])] += 2
        if res_team2[int(e[2])] >= 2:
            res_team2[int(e[2])] = -100
            print(team2, e[2], e[0])
