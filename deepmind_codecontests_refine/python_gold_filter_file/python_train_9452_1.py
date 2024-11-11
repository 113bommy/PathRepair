from collections import deque
N,M,P,*L = map(int, open(0).read().split())
INF = 10**9
Els = []
dic = [[] for i in range(N+1)]
rdic = [[] for i in range(N+1)]
for a,b,c in zip(*[iter(L)]*3):
  dic[a].append((b,c-P))
  rdic[b].append((a,c-P))
  Els.append((a,b,-c+P))
ok1 = [False]*(N+1)
ok1[1] = True
q = deque([1])
while q:
  v = q.popleft()
  for p,c in dic[v]:
    if not ok1[p]:
      ok1[p] = True
      q.append(p)

ok2 = [False]*(N+1)
ok2[N] = True
q = deque([N])
while q:
  v = q.popleft()
  for p,c in rdic[v]:
    if not ok2[p]:
      ok2[p] = True
      q.append(p)

ok = [a&b for a,b in zip(ok1,ok2)]

dist = [INF]*(N+1)
dist[1] = 0
cnt = 0
while True:
  end = True
  for a,b,c in Els:
    if ok[a] and ok[b] and dist[a]!=INF and dist[b]>dist[a]+c:
      end = False
      dist[b] = dist[a]+c
  if end:
    print(max(0,-dist[N]))
    break
  cnt += 1
  if cnt>N:
    print(-1)
    break