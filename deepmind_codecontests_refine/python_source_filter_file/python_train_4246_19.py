N,M=map(int,input().split())
F = [set() for _ in range(N)]
for _ in range(M):
  a,b = map(lambda x: int(x)-1, input().split())
  F[a].add(b)
  F[b].add(a)

from collections import deque
 
def bfs():
  ans = 0
  done = set()
  for i in range(N):
    if i in done: continue
    queue = deque([i])
    num = 0
    while queue:
      p = queue.popleft()
      for p2 in F[p]:
        if p2 in done: continue
        done.add(p2)
        queue.append(p2)
        num += 1
    ans = max(ans,num)
  return ans
print(bfs())