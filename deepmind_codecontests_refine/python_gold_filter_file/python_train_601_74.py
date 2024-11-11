N,M=map(int,input().split())
S=list(map(int,input().split()))
T=list(map(int,input().split()))
MOD=10**9+7
ans=0
dp=[[0]*(M+1) for _ in range(N+1)]
ans=[[0]*(M+1) for _ in range(N+1)]
for i in range(N):
    for j in range(M):
        if S[i]==T[j]:
            dp[i+1][j+1]=(ans[i][j]+1)%MOD
        else:
            dp[i+1][j+1]=0
        ans[i+1][j+1]=(ans[i][j+1]+ans[i+1][j]-ans[i][j]+dp[i+1][j+1])%MOD
print((ans[N][M]+1)%MOD)