from collections import Counter
n = int(input())
a = [tuple(map(int, input().split())) for _ in range(n)]
c = Counter((y[0] - x[0], y[1] - x[1]) for i, x in enumerate(a) for y in a[:i])
print(n - max(c.values(), default=0))
