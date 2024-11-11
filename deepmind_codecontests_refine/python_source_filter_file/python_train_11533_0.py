H, W = map(int, input().split())
sh, sw = map(int, input().split())
gh, gw = map(int, input().split())

sh += 1
sw += 1
gh += 1
gw += 1

S = [0]*(H+4)
S[0] = '*'*(W+4)
S[1] = '*'*(W+4)
S[-2] = '*'*(W+4)
S[-1] = '*'*(W+4)
for h in range(2,H+2):
  S[h] = '**' + input() + '**'

visited = [[float('inf')]*(W+4) for _ in range(H+4)]
dh1 = [0,1,0,-1]
dw1 = [1,0,-1,0]
dh2 = [2,2,2,2,2,1,1,1,1,0,0,-1,-1,-1,-1,-2,-2,-2,-2,-2]
dw2 = [-2,-1,0,1,2,-2,-1,1,2,-2,2,-2,-1,1,2,-2,-1,0,1,2]

from collections import deque
d = deque()

d.append((sh,sw,0))

while len(d)>0:
  h,w,cnt = d.popleft()
  if visited[h][w]<=cnt:
    continue
  visited[h][w] = cnt
  for i in range(4):
    h1 = h+dh1[i]
    w1 = w+dw1[i]
    if S[h1][w1]=='.':
      if visited[h1][w1]>cnt:
        d.append((h1,w1,cnt))
  for i in range(20):
    h2 = h+dh2[i]
    w2 = w+dw2[i]
    if S[h2][w2]=='.':
      if visited[h2][w2]>cnt+1:
        d.append((h2,w2,cnt+1))
ans = visited[gh][gw] if visited[gh][gw]<float('inf') else -1
print(ans)