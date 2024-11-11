from collections import deque
N = int(input())
S = []
for _ in range(N):
  S.append(input())
  
G = [[] for _ in range(N)]
for i in range(N):
  for j in range(i+1,N):
    if S[i][j] == '1':
      G[i].append(j)
      G[j].append(i)

# 2部グラフ判定
visited = [False] * N
willSearch = [False] * N
Color = [-1] * N
Q = deque()
Q.append((0,0))
while Q:
  now, c = Q.pop()
  visited[now] = True
  Color[now] = c
  for nxt in G[now]:
    if Color[nxt] >= 0 and c == Color[nxt]:
      #隣接色が一致してしまった
      print(-1)
      exit(0)
    if visited[nxt] or willSearch[nxt]:
      continue
    Q.append((nxt,1-c)) # 1-cで0/1を交換
    willSearch[nxt] = True
    
INF = 1000
D = [[INF for _ in range(N) ]  for _ in range(N)]
for i in range(N):
  for nxt in G[i]:
    D[i][nxt] = 1
    D[nxt][i] = 1
    
#Warshall-Floyd
for k in range(N):
  for i in range(N):
    for j in range(N):
      #print(i,j,k)
      D[i][j] = min(D[i][j], D[i][k] + D[k][j])
      
#print(*D, sep="\n")

ans = 0
for i in range(N):
  for j in range(i+1,N):
    ans = max(ans, D[i][j])
    
print(ans+1)