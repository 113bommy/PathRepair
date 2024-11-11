import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()  # ignore trailing spaces
nl = lambda: list(map(int, stdin.readline().split()))

n, K = na()
a = na()
ans = float('inf')
for i in range(2**(n-1)):
    colors = 1
    cost = 0
    tmp = a[0]
    for k in range(n-1):
        if tmp < a[k+1]:
            colors += 1
            tmp = a[k+1]
            continue
        if (i >> k) & 1:
            cost += tmp - a[k+1] + 1
            colors += 1
            tmp += 1
    if colors >= K:
        ans = min(ans, cost)
print(ans)
