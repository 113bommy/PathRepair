import sys
read = lambda: sys.stdin.readline().strip()
readi = lambda: map(int, read().split())
from collections import *

n, m, _x = readi()
keys = defaultdict(list)
shifts = list()

for i in range(n):
    row = read()
    for j, key in enumerate(row):
        if key == "S":
            shifts.append((i, j))
        else:
            keys[key].append([i, j, float('inf')])

for (i, j) in shifts:
    for key in keys:
        for i, button in enumerate(keys[key]):
            x, y, minDist = button
            dist = ((i - x)**2 + (j - y)**2)**0.5
            keys[key][i][2] = min(dist, minDist)

q = read()
outStr = read()
ans = 0
for out in outStr:
    key = out.lower()
    if key not in keys:
        print(-1)
        break
    if out.isupper() and not shifts:
        print(-1)
        break
    if out.isupper():
        for (x, y, dist) in keys[key]:
            if dist < _x:
                break
        else:
            # print(key, dist)
            ans += 1
else:
    print(ans) 

