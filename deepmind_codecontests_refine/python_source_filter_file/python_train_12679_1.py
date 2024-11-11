n,m,l=map(int,input().split())
inf=10000000000
g=[[inf for i in range(n)] for j in range(n)]
for i in range(m):
    a,b,c=map(int,input().split())
    g[a-1][b-1]=c
    g[b-1][a-1]=c
for k in range(n):
    for i in range(n):
        for j in range(n):
            g[i][j]=min(g[i][j],g[i][k]+g[k][j])
r=[[inf for i in range(n)] for j in range(n)]
for i in range(n):
    for j in range(n):
        if g[i][j]<=l:
            r[i][j]=1
        elif g[i][j]>=inf:
            r[i][j]=inf
for k in range(n):
    for i in range(n):
        for j in range(n):
            r[i][j]=min(r[i][j],r[i][k]+r[k][j])
q=int(input())
for i in range(q):
    s,e=map(int,input().split())
    if r[s-1][e-1]>=inf:
        print(-1)
    else:
        print(r[s-1][e-1]-1)