from sys import stdin
from collections import defaultdict
input = stdin.readline

n, k = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
d = defaultdict(list)
operations = 0
for i in range(n):
    x = a[i]
    d[x].append(0)
    c = 0
    while x > 0:
        x //= 2
        c += 1
        d[x].append(c)
    d[0].append(c)
b = [list(sorted(i)) for i in d.values()]
ans = float("inf")
for i in b:
    if len(i) < k:
        continue
    s = 0
    for j in range(k):
        s += i[j]
    ans = min(ans, s)
print(ans)