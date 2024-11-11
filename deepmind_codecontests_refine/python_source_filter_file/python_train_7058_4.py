from heapq import heappush, heappop
N, *L = map(int, open('0').read().split())
dic = [[] for i in range(N)]
ans = [-1]*N
cnt = [0]*N
hq = []
for a,b in zip(*[iter(L[:2*(N-1)])]*2):
  a -= 1
  b -= 1
  dic[a] += [b]
  dic[b] += [a]
  cnt[a] += 1
  cnt[b] += 1
C = L[2*(N-1):]
C.sort()
for i in range(N):
  heappush(hq,(cnt[i],i))
arg = 0
m = 0
while True:
  c, i = heappop(hq)
  if ans[i]!=-1:
    continue
  m += C[arg]*cnt[i]
  ans[i] = C[arg]
  arg += 1
  if arg==N:
    break
  for v in dic[i]:
    cnt[v] -= 1
    heappush(hq,(cnt[v],v))
print(m)
print(*ans)