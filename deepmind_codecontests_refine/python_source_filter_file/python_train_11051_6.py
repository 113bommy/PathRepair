from bisect import bisect
n, m = map(int, input().split())
b = sorted(map(int, input().split()))
g = sorted(map(int, input().split()))
if g[0] > b[-1]:
    print(sum(g) + b[-1] + b[-2] * (m - 1) + m * sum(b[:-2]))
elif g[0] == b[1]:
    i = bisect(g, b[-1])
    print(sum(g) + m * sum(b[:-1]))
else:
    print(-1)