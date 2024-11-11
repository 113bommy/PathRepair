import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

H, W, K = mapint()
y1, x1, y2, x2 = mapint()
pond = [list(input()) for _ in range(H)]
from collections import deque
Q = deque([(y1-1, x1-1)])

inf = 10**18
dist = [[inf]*W for _ in range(H)]
dist[y1-1][x1-1] = 0
while Q:
    y, x = Q.popleft()
    if y==y2-1 and x==x2-1:
        break
    for dy, dx in ((1, 0), (0, 1), (-1, 0), (0, -1)):
        for i in range(1, K+1):
            ny, nx = y+dy*i, x+dx*i
            if ny<0 or ny>=H or nx<0 or nx>=W:
                break
            if pond[ny][nx]=='@':
                break
            if dist[ny][nx]<dist[y][x]:
                break
            if dist[ny][nx]>dist[y][x]+1:
                dist[ny][nx] = dist[y][x]+1
                Q.append((ny, nx))
if dist[y2-1][x2-1]>=10**17:
    print(-1)
else:
    print(dist[y2-1][x2-1])