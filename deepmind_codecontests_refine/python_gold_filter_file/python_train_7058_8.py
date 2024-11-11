import sys
stdin = sys.stdin
sys.setrecursionlimit(10**6)
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
nn = lambda: list(stdin.readline().split())
ns = lambda: stdin.readline().rstrip()

n = ni()
g = [[] for i in range(n)]

for i in range(n-1):
  a,b = na()
  g[a-1].append(b-1)
  g[b-1].append(a-1)

c = na()
c = sorted(c)

print(sum(c)-c[-1])

ans = [0]*n
st = [0]

while st:
  d = st.pop()
  ans[d] = c.pop()
  for v in g[d]:
    if ans[v] == 0:
      st.append(v)

print(' '.join([str(s) for s in ans]))