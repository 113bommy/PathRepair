n,m=map(int,input().split())
a=[[0]*n for i in range(n)]
for i in range(m):
    x,y=map(int,input().split())
    a[x-1][y-1]=a[y-1][x-1]=1;
b=[-1]*n
b[1]=0
q=[0]
while q:
    u=q.pop(0)
    for v in range(n):
        if a[u][v]!=a[0][n-1] and b[v] ==-1:
            b[v]=b[u]+1
            q.append(v)
print(b[n-1])

