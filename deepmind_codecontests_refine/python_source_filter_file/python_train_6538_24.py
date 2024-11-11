from collections import deque
H, W = map(int, input().split())
INF = 10**9
sheet = []
log = [[True]*W for i in range(H)]
step = [(-1,0),(1,0),(0,-1),(0,1)]
stuck = deque()
ans = -1

for i in range(H):
  line = input()
  for j in range(W):
    if line[j]=='#':
      stuck += [(i,j,0)]
      log[i][j] = False
      
while stuck:
  y, x, m = stuck.popleft()
  for s in step:
    dx, dy = s
    if x+dx<0 or x+dx>W-1 or y+dy<0 or y+dy>H-1:
      continue
    if log[y+dy][x+dx]:
      log[y+dy][x+dx]=False
      stuck += [(y+dy, x+dx, m+1)]
      if ans<m+1:
        ans = m+1
      
print(ans)