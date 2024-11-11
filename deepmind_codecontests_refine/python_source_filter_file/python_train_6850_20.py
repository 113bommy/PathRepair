from collections import deque
n,m = map(int,input().split())
G = [[[] for _ in range(3)] for _ in range(n)]
for _ in range(m):
    u,v = map(int,input().split())
    u -= 1
    v -= 1
    G[u][0].append((v,1))
    G[u][1].append((v,2))
    G[u][2].append((v,0))
s,t = map(int,input().split())
s -= 1
t -= 1

dist = [[-1]*3 for _ in range(n)]
dist[0][0] = 0
Q = deque([(s,0)])
while Q:
    now,r = Q.popleft()
    for nxt,nr in G[now][r]:
        if dist[nxt][nr] != -1: continue
        dist[nxt][nr] = dist[now][r]
        if r == 2: dist[nxt][nr] += 1
        Q.append((nxt,nr))
# print(dist)
print(dist[t][0])