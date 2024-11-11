N, M = map(int, input().split())
R = []
for _ in range(N):
    R.append(tuple(map(int, input().split())))
P = []
for _ in range(M):
    P.append(tuple(map(int, input().split())))

D = [0] * (10 ** 6 + 1)

for rx, ry in R:
    for px, py in P:
        if px >= rx and py >= ry:
            D[px - rx] = max(D[px - rx], py - ry + 1)

result = 10 ** 6
my = 0
for x in range(len(D) - 1, -1, -1):
    my = max(my, D[x])
    result = min(result, my + x)

print(result)
