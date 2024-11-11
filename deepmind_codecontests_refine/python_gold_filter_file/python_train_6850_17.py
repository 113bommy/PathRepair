from collections import defaultdict, deque
N, M = map(int, input().split())
dic = defaultdict(list)
for i in range(M):
  u, v = map(int, input().split())
  dic[u-1] += [v-1]
S, T = map(int, input().split())
S -= 1
T -= 1
dist = [[float('inf')]*3 for i in range(N)]
dist[S][0] = 0
q = deque([(S,0)])
flag = False
cnt = 0
while q:
  cnt += 1
  e, m = q.popleft()
  n = (m+1)%3
  for p in dic[e]:
    if p==T:
      flag = True
    if dist[p][n]>dist[e][m]+1:
      dist[p][n] = dist[e][m]+1
      q += [(p,n)]
if flag:
  ans = dist[T][0] if dist[T][0]!=float('inf') else -1
  print(ans//3)
else:
  print(-1)