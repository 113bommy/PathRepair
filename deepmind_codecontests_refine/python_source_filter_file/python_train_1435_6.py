n,m = map(int,input().split())
d = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    d[a-1].append(b-1)
    d[b-1].append(a-1)

ans = [-1]*n
ans[0] = 0
from collections import deque
q = deque([0])
while q:
    u = q.popleft()
    for v in d[u]:
        if ans[v]==-1:
            ans[v] = u
            q.append(v)
print('Yes')
for i in ans[1:]:
    print(i)