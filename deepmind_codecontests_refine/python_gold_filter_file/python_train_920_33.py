N,x = map(int,input().split())
DP = [list(map(int,input().split()))]+[[float('inf')]*(N) for i in range(N-1)]
for i in range(N-1):
    for j in range(N):
        DP[i+1][j] = min(DP[i][j-1],DP[i][j])
ans = float('inf')
for i in range(N):
    ans = min(ans,sum(DP[i])+i*x)
print(ans)