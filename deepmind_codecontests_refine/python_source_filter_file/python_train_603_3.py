from collections import defaultdict
N, M = map(int, input().split())
A = list(map(int, input().split()))

d = defaultdict(int)
ans = 0
s = 0
d[0] = 1
for i, a in enumerate(A):
    a %= M
    s += a
    ans += d[s%M]
    d[s % M] += 1

print(ans, d)