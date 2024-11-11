T = int(input())
res = [[0,0] for _ in range(T)]

for i in range(T):
    P = int(input())
    res[i][0] = 2; res[i][1] = P // 2

[print(r[0], r[1]) for r in res]
