import sys
sys.setrecursionlimit(10**9)

N,K = map(int,input().split())
P = [ i-1 for i in list(map(int,input().split())) ]
C = list(map(int,input().split()))
ans = -float('inf')

for i in range(N):
  cycle = []
  tot = 0
  nex = i
  while True:
    nex = P[nex]
    cycle.append(C[nex])
    tot += C[nex]
    if nex == i: break

  l = len(cycle)
  t = 0
  for j in range(l):
    t += cycle[j]
    if j+1 > K: break
    now = t
    if tot > 0:
      now += tot*((K-(j+1))//l)
    ans = max(ans, now)

print(ans)
