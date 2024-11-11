N,K=map(int, input().split())
X,Y=map(list,zip(*[list(map(int,input().split())) for i in range(N)]))
x=sorted(X)
y=sorted(Y)
c=[[0]*(N+1) for i in range(N+1)]
for i in range(N):
    c[x.index(X[i])+1][y.index(Y[i])+1]=1
for i in range(N):
    for j in range(N):
        c[i+1][j+1]+=c[i][j+1]+c[i+1][j]-c[i][j]
ans=5*10**18
for t in range(1,N+1):
    for b in range(t+1,N+1):
        for l in range(1,N+1):
            for r in range(l+1,N+1):
                count=c[b][r]-c[b][l-1]-c[t-1][r]+c[t-1][l-1]
                if count>=K:
                    ans=min(ans,(x[r-1]-x[l-1])*(y[b-1]-y[t-1]))
                    break
print(ans)