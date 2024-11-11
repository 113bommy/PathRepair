from collections import defaultdict as dd

n = int(input())
_s = list(map(ord, list(input())))
s,t = _s[:n], _s[:n-1:-1]
d = dict()
mod = 10**9 + 9

def get(st):
  for bit in range(1<<n):
    u = v = 0
    for j,e in enumerate(s):
      if bit & (1<<j):
        u = (u*100 + e)%mod
      else:
        v = (v*100 + e)%mod
    yield (u,v)

ans = 0
d = dd(int)
for x in get(s): d[x] += 1
for x in get(t): ans += d[x]
print(ans)