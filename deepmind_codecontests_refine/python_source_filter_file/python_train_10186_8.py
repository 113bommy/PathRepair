n,m,r=map(int, input().split())
s=[[100000]*n for i in range(n)]
t=list(map(int, input().split()))
for i in range(m):
    a,b,c=map(int, input().split())
    s[a-1][b-1]=c
    s[b-1][a-1]=c
 
for k in range(n):
    for i in range(n):
        for j in range(n):
            s[i][j]=min(s[i][j],s[i][k]+s[k][j])
ans=float('inf')
from itertools import permutations
for i in permutations(t):
    an=0
    for j in range(r-1):
        an+=s[i[j]-1][i[j+1]-1]
    ans=min(ans,an)
print(ans)