N,K=map(int,input().split())
A=list(map(int,input().split()))
d=[[0]*(K+2) for i in range(N+1)]
d[0]=[0]+[1]*(K+1)
m=10**9+7
for i in range(N):
    for j in range(K+1):
        d[i+1][j+1]=(d[i][j+1]-d[i][max(0,j-A[i])]+d[i+1][j])%m
print((d[-1][-1]-d[-1][-2])%m)