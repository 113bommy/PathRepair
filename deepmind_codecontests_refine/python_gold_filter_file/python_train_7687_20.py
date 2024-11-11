import itertools
n,m=map(int,input().split())
l=[[0]*n for i in range(n)]
for i in range(m):
    a,b=map(int,input().split())
    l[a-1][b-1]=1
    l[b-1][a-1]=1
d=[int(i)+1 for i in range(n)]
ans=chk=0
for i in list(itertools.permutations(d,n)):
    chk=1
    if i[0]!=1: continue
    for j in range(n-1):
        chk*=l[i[j+1]-1][i[j]-1]
    ans+=chk
print(ans)