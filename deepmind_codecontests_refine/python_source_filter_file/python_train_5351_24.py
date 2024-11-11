import sys
from collections import defaultdict

r, c = map(int, sys.stdin.readline().split())
grid = list(map(lambda l: sys.stdin.readline().strip(), range(r)))
frow = defaultdict(lambda: False)
fcol = defaultdict(lambda: False)

for i in range(r):
    for j in range(c):
        if grid[i][j] == 'S':
            frow[i] = True
            fcol[j] = True

ans = 0
for i in range(r):
    for j in range(c):
        if not frow[i] or not frow[j]:
            ans += 1
sys.stdout.write(str(ans))
