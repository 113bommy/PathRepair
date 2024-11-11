# ABC132 E
from collections import deque

f=lambda:map(int,input().split())
N,M=f()
G=[[] for _ in [0]*(N+1)]

for _ in [0]*M:
    a,b=f()
    G[a].append(b)
S,T=f()
S=(S,0)
T=(T,0)

q=deque()
q.append(S)
F=set()
res=-1
while q:
    node,r=q.popleft()
    if (node,r%3) in F:
        continue
    if (node,r%3) == T:
        res=r//3
        break
    F.add((node,r%3))
    for next_node in G[node]:
        if (next_node,(r+1)%3) in F:
            continue
        q.append((next_node,r+1))
print(res)