from collections import defaultdict
from heapq import heappush, heappop
 
n, m = map(int, input().split())
adj = defaultdict(list)
 
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
    
for k,v in adj.items():
    adj[k].sort()
    
v = [0]*(n+1)
perm = []
q = [1]
 
while q:
    e = heappop(q)
    perm.append(e)
    
    for i in adj[e]:
        if not v[i]:
            v[i] = 1
            heappush(q, i)
            
print(*perm)