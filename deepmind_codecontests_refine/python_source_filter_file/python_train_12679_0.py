n,m,l=map(int,input().split())
inf=100000000000
wf=[[inf]*n for i in range(n)]
for i in range(m):
    a,b,c=map(int,input().split())
    wf[a-1][b-1]=c
    wf[b-1][a-1]=c
for i in range(n):
    wf[i][i]=0
for i in range(n):
    for j in range(n):
        for k in range(n):
            wf[i][j]=min(wf[i][j],wf[i][k]+wf[k][j])
for i in range(n):
    for j in range(n):
        if i!=j:
            wf[i][j]=1 if wf[i][j]<=l else inf
for i in range(n):
    for j in range(n):
        for k in range(n):
            wf[i][j]=min(wf[i][j],wf[i][k]+wf[k][j])
q=int(input())
for i in range(q):
    s,t=map(int,input().split())
    x=wf[s-1][t-1]
    print(-1 if x==inf else wf[s-1][t-1]-1)