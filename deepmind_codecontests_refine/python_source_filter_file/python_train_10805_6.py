import sys
input = sys.stdin.readline

N = int(input().strip())
M = N*(N-1)//2

graph = [[] for i in range(M)]
in_cnt = [0 for i in range(M)]
for x in range(N):
  l = list(map(int,input().split()))
  y = l[0]
  b,s = max(x,y),min(x,y)
  prev = (b-1)*(b-2)//2+s-1
  for y in l[1:]:
    b,s = max(x,y),min(x,y)
    now = (b-1)*(b-2)//2+s-1
    graph[prev].append(now)
    in_cnt[now] += 1 
    prev = now

d = [1 for k in range(M)]
q = [i for i in range(M) if not in_cnt[i]]

if not q:
  print(-1)
  exit()
ans = 0
while q:
  x = q.pop()
  for y in graph[x]:
    d[y] = max(d[y],d[x]+1)
    ans = max(ans,d[y])
    in_cnt[y] -= 1
    if not in_cnt[y]:
      q.append(y)
if [i for i in range(M) if in_cnt[i]]:
  print(-1)
  exit()

print(ans)