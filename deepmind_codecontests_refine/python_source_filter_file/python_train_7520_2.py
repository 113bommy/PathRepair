import sys
input = sys.stdin.readline
from collections import deque

n = int(input())
cost = []
p = [-1]*(n)
y = []
for i in range(n):
    a,b,c = map(int,input().split())
    cost.append(a)
    y.append(c-b)

if sum(y):
    print(-1)
    exit()

e = [[] for i in range(n)]
for i in range(n-1):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    e[a].append(b)
    e[b].append(a)

topo = []
q = deque([])
q.append((1,-1))
while q:
    now,bef = q.popleft()
    topo.append(now)
    for nex in e[now]:
        if nex == bef:
            continue
        cost[nex] = min(cost[nex],cost[now])
        p[nex] = now
        q.append((nex,now))

ans = 0
for i in topo[::-1]:
    if y[i]*y[p[i]] < 0:
        ans += cost[p[i]]*min(abs(y[i]),abs(y[p[i]]))
    y[p[i]] += y[i]
print(ans*2)