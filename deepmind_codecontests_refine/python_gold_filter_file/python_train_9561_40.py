from itertools import combinations
n, k = map(int, input().split())
xy = []
xx = []
yy = []
for _ in range(n):
    x, y = map(int, input().split())
    xy.append((x, y))
    xx.append(x)
    yy.append(y)
xx.sort()
yy.sort()
ans = 10**20
for x1, x2 in combinations(xx, 2):
    for y1, y2 in combinations(yy, 2):
        tmp = 0
        for x, y in xy:
            if x1<=x<=x2 and y1<=y<=y2:
                tmp += 1
        if tmp<k:
            continue
        ans = min(ans, (x2-x1)*(y2-y1))
print(ans)