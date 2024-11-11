#054_C
from itertools import permutations
n,m=map(int,input().split())
edges=[[False for _ in range(n)] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a,b=a-1,b-1
    edges[a][b]=edges[b][a]=True

ans=0
for l in permutations(range(1,n),n-1):
    l=[0]+list(l)
    if all(edges[l[i]][l[i+1]] for i in range(n-1)):
        ans+=1
print(ans)