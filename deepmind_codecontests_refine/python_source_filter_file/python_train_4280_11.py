import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
from collections import defaultdict

n, m = map(int, input().split())
adj = defaultdict(list)

for i in range(m):
    x, y = map(int, input().split())
    adj[x].append(y)
    adj[y].append(x)
    
cmps = 0
v = [0]*(n+1)

for i in range(1, 1+n):
    if not v[i]:
        q = [i]
        while q:
            e = q.pop()
            v[e] = 1
                
            for j in adj[e]:
                if not v[j]:
                    q.append(j)
                    
        cmps += 1
           
print("FHTAGN!" if n==m and cmps else "NO")