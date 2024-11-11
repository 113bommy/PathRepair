n, m, h = map(int, input().split())

res = [[-1 for _ in range(m)] for _ in range(n)]

for i, h in enumerate([int(x) for x in input().split()]):
    # for all 'n' res[n][i] = h
    for j in range(n):
        res[j][i] = h

for i, h in enumerate([int(x) for x in input().split()]):
    # for all 'm' res[i][m] <= h
    for j in range(m):
        if res[i][j] > h:
            res[i][j] = h

for r in range(n):
    for c, h in enumerate([int(x) for x in input().split()]):
        res[r][c] *= h


print(str(res).replace('], [', '\n').replace(',', '').replace('[[', '').replace(']]', ''))

