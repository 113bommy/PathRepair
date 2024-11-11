N,M = map(int,input().split())

V = [[] for _ in range(M)]

for _ in range(M):
    a,b = map(int,input().split())
    a = a-1
    b = b-1
    V[a].append(b)
    V[b].append(a)

from collections import deque

q = deque([0])

ans = [-1]*N
ans[0] = 0

while q:
    v = q.popleft()
    for nv in V[v]:
        if ans[nv] == -1:
            ans[nv] = v + 1
            q.append(nv)

print("Yes")
print(*ans[1:],sep="\n")
