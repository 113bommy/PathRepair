from heapq import heappush, heappop

N, K = map(int, input().split())
h = []
for i in range(N):
  t, d = map(int, input().split())
  heappush(h, (-d, t))

# initial
res = 0
sum = 0
q = []
used = {}
for i in range(K):
  (d, t) = heappop(h)
  if t not in used:
    used[t] = 1
  else:
    heappush(q, (-d, t))
  sum += -d
res = len(used)*len(used)+sum

# swap minimum
while q:
  (d, t) = heappop(h)
  if t not in used:
    used[t] = 1
    m, _ = heappop(q)
    sum = sum - m - d
  res = max(res, len(used)*len(used) + sum)
  
print(res)