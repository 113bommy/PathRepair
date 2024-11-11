from collections import deque
import sys
input = sys.stdin.readline
h,w = map(int,input().split())
a = [list(input().rstrip()) for i in range(h)]
q = deque()
for i in range(h):
  for j in range(w):
    if a[i][j] == "#":
      a[i][j] = 0
      q.append((i,j,0))
    else:
      a[i][j] = -1
while q:
  s,t,cnt = q.popleft()
  for ns,nt in ((s+1,t),(s-1,t),(s,t+1),(s,t-1)):
    if 0<=ns<=h-1 and 0<=nt<=w-1 and a[ns][nt] == -1:
      q.append((ns,nt,cnt+1))
      a[ns][nt] = cnt+1
ans = 0
for i in range(h):
  for j in range(w):
    ans = max(ans,a[i][j])
print(ans)