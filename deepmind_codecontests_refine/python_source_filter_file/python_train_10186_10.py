n,m,R=[int(x) for x in input().split()]
r=[int(x) -1 for x in input().split()]
d=[[float("inf") for _ in [0]*n] for _ in [0]*n]
for i in range(n):
    d[i][i]=0
for i in [0]*m:
    a,b,c=[int(x) for x in input().split()]
    d[a-1][b-1]=d[b-1][a-1]=c
from itertools import product,permutations
for i,j,k in product(range(n),range(n),range(n)):
    if d[i][j] >d[i][k]+d[k][j]:
        d[i][j]=d[i][k]+d[k][j]
def Long(args):
    ans=0
    for i in range(len(args)-1):
        ans+=d[args[i+1]][args[i]]
    return ans
print(min(Long(i) for i in permutations(r)))