import sys
readline = sys.stdin.readline
readlines = sys.stdin.readlines

N = int(readline())
XY = (tuple(int(x)-1 for x in line.split()) for line in readlines())

graph = [[] for _ in range(N)]
for x,y in XY:
    graph[x].append(y)
    graph[y].append(x)

visited = [True] + [False] * (N-1)
q = [0]
ord = [0]
par = [0] * N
while q:
    x = q.pop()
    for y in graph[x]:
        if visited[y]:
            continue
        ord.append(y)
        par[y] = x
        visited[y] = True
        q.append(y)

G = [0] * (N+1)
for x in ord[:0:-1]:
    p = par[x]
    G[p] ^= (G[x]+1)

answer = 'Alice' if G[0] != 0 else 'Bob'
print(answer)
