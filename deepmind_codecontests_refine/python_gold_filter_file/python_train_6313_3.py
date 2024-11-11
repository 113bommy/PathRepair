from bisect import bisect_left
from itertools import accumulate

n = int(input())
v = [int(x) for x in input().split()]
t = [int(x) for x in input().split()]
ts = [0] + list(accumulate(t))

m = [1] * n
d = [0] * n
for i in range(n):
    m[i] += m[i-1] if i > 0 else 0
    j = bisect_left(ts, v[i] + ts[i], lo=i+1) - 1  # indice ou i disparait (à la fin du jour j, tout v_i a fondu 
    if j < n:
        m[j] -= 1
        d[j] += v[i] - (ts[j] - ts[i])

s = []
for i in range(n):
    s += [m[i] * t[i] + d[i]]

print(' '.join(map(str, s)))