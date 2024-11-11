import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

from collections import defaultdict

n, m = map(int, input().split())
adj = defaultdict(list)

for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)
    
cmps = []
v = [0]*(n+1)

for i in range(1, n+1):
    if not v[i]:
        q = [i]
        mn = 1e18
        mx = 0
        
        while q:
            e = q.pop()
            mn = min(e, mn)
            mx = max(e, mx)
            v[e] = 1
            
            for j in adj[e]:
                if not v[j]:
                    q.append(j)
        
        cmps.append((mn, mx))

ct = 0
cmps.sort(key=lambda x: x[0])
bg = cmps[0][1]
for i in cmps[1:]:
    if i[0] < bg:
        ct += 1
    bg = max(bg, i[1])

print(ct)