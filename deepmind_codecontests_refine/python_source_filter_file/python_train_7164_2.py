N,M,Q=map(int, input().split())
L=[[0]*(N+1) for _ in range(N+1)]
for i in range(M):
    l,r=map(int, input().split())
    L[l][r]+=1

#print(L)
for i in range(1,N+1):
    for j in range(1,N+1):
        L[i][j]+=L[i][j-1]+L[i-1][j]-L[i-1][j-1]

#print(L)

for i in range(Q):
    p,q=map(int, input().split())
    ans=L[q][q]-L[p-1][q]+L[q][p-1]+L[p-1][p-1]
    print(ans)