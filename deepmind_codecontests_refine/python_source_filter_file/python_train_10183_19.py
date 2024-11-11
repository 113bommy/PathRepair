from heapq import heappush, heappop
N, K = map(int, input().split())
log = [0]*N
pre = []
ls = []
for i in range(N):
  t, d = map(int, input().split())
  t = t-1
  heappush(ls,(-d,t))
v = 0
n = 0
for i in range(K):
  d, t = heappop(ls)
  d = -d
  log[t] += 1
  v += d
  if log[t]>1:
    heappush(pre,(d,t))
  else:
    n += 1
v += n*n
ans = v
while ls:
  d, t = heappop(ls)
  if log[t]>0:
    continue
  log[t] += 1
  d = -d
  pv = v
  x, y = heappop(pre)
  v -= x
  v += d
  v += 2*n+1
  n += 1
  if ans<v:
    ans = v
print(ans)