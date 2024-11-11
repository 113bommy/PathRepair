def f(x, p):
    q = []
    while x:
        q.append(x)
        x = p[x]
    return q
from collections import defaultdict
n, k = map(int, input().split())
t = list(map(int, input().split()))
p = [0] * (n + 1)
for i, j in enumerate(t, 1):
    p[j] = i
p = [f(i, p) for i, j in enumerate(t, 1) if j == 0]
s = defaultdict(int)
for i in p:
    if k in i: t = {i.index(k) + 1}
    else: s[len(i)] += 1
s = [list(range(i, k * i + 1, i)) for i, k in s.items()]
for q in s:
    t |= {x + y for x in q for y in t}
print('\n'.join(map(str, sorted(list(s)))))