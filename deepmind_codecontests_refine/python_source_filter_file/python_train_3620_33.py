n = int((input()))
U, R, D, L = [], [], [], []
for _ in range(n):
    x, y, d = input().split()
    x = int(x)
    y = int(y)
    (U if d == 'U' else R if d == 'R' else D if d == 'D' else L).append((x, y))
INF = 1001001001001
ans = INF
def front_crash(u, d):
    global ans
    u.sort()
    d.sort()
    i = 0
    j = 0
    while i < len(u) and j < len(d):
        ut = [u[i][1]]
        while i + 1 < len(u) and u[i][0] == u[i+1][0]:
            i += 1
            ut.append(u[i][1])
        dt = []
        while j + 1 < len(d) and d[j+1][0] < u[i][0]:
            j += 1
        while j < len(d) and d[j][0] == u[i][0]:
            dt.append(d[j][1])
            j += 1
        q = 0
        for y1 in ut:
            while q < len(dt) and dt[q] < y1:
                q += 1
            if q == len(dt):
                break
            y2 = dt[q]
            ans = min(ans, (y2 - y1) * 5)
        i += 1
front_crash(U, D)
front_crash(*(list(map(lambda p: (p[1], p[0]), t)) for t in [R, L]))
from collections import defaultdict
from bisect import bisect_left
def side_crash(u, r):
    global ans
    d = defaultdict(list)
    u.sort()
    for x, y in u:
        d[x+y].append(x)
    for x, y in r:
        dxy = d[x+y]
        i = bisect_left(dxy, x)
        if i < len(dxy):
            ans = min(ans, (dxy[i] - x) * 10)
side_crash(U, R)
side_crash(*([(y, 200000 - x) for x, y in t] for t in [L, U]))
side_crash(*([(200000 - x, 200000 - y) for x, y in t] for t in [D, L]))
side_crash(*([(200000 - y, x) for x, y in t] for t in [R, D]))

print(ans if ans < INF else 'SAFE')