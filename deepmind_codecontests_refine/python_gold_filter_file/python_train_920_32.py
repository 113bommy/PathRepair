N,x = map(int,input().split())
*A, = map(int,input().split())
c = [A[:] for _ in [0]*(N)]
ans = sum(A)
for i in range(1,N):
    for j in range(N):
        c[i][j] = min(c[i-1][j-1],c[i][j])
    ans = min(ans,sum(c[i])+x*i)
print(ans)