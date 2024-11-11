from heapq import heappush, heappop
N, K , *P = map(int, open(0).read().split())
mhq = []
Mhq = []
for c in P[:K]:
  heappush(mhq,c)
  heappush(Mhq,-c)

ans = 1
log = set()
for i,c in enumerate(P[K:]):
  while mhq[0] in log:
    heappop(mhq)
  while -Mhq[0] in log:
    heappop(Mhq)
  d = P[i]
  m = mhq[0]
  M = -Mhq[0]
  log.add(d)
  heappush(mhq,c)
  heappush(Mhq,-c)
  if not (m==d and M<c):
    ans += 1
p = P[0]
m = 1
x = 0
for c in P[1:]:
  if p<c:
    m += 1
  else:
    if m>=K:
      x += 1
    m = 1
  p = c
if m>=K:
  x += 1
if x!=0:
  ans -= x-1
print(ans)