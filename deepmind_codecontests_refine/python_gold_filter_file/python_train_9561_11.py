from itertools import combinations
import sys
sys.setrecursionlimit(10 ** 7)
input = sys.stdin.readline

n, k = map(int, input().split())
x = [0]* n
y = [0]* n
for i in range(n):
    x[i], y[i] = map(int, input().split())

xc = list(combinations(x,2))
yc = list(combinations(y,2))
ans = 4*10**18

for yy in yc:
    u = max(yy)
    d = min(yy)
    for xx in xc:
        r = max(xx)
        l = min(xx)
        count = 0
        for i in range(n):
            if l <= x[i] <=r and d <= y[i] <=u: count += 1
        if count >= k:
            ans = min(ans, (u-d)*(r-l))

print(ans)