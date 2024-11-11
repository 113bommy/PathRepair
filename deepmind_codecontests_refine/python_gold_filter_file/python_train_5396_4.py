from collections import deque
H, W = map(int,input().split())
G = [input() for _ in range(H)]
white = 0
dist = [(-1, 0), (1, 0), (0, -1), (0, 1)]
visited = set()
for line in G:
  white+=line.count('.')

D = deque()
D.append((0,0,1))
rout = -1
while D:
  h, w, c = D.popleft()
  if h == H-1 and w == W-1:
    rout = c
    break
  if (h, w) in visited or G[h][w] == '#':
    continue
  else:
    visited.add((h, w))
  for dh, dw in dist:
    if (0<=h+dh<H) and (0<=w+dw<W):
      if (h+dh, w+dw) not in visited and G[h+dh][w+dw] != '#':
        D.append((h+dh, w+dw, c+1))
        
if rout == -1:
  print(rout)
else:
  print(white-rout)

