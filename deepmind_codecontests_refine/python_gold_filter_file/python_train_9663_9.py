S=input()
N=len(S)
INF=1e9+7
dp=[[0]*4 for _ in range(N+1)]
dp[0][0]=1
for i in range(N):
    if S[i]=="?":
        for j in range(4):
            dp[i+1][j]+=dp[i][j]*3%INF
    else:
        for j in range(4):
            dp[i+1][j]+=dp[i][j]%INF
    if S[i]=="A" or S[i]=="?":
        dp[i+1][1]+=dp[i][0]%INF
    if S[i]=="B" or S[i]=="?":
        dp[i+1][2]+=dp[i][1]%INF
    if S[i]=="C" or S[i]=="?":
        dp[i+1][3]+=dp[i][2]%INF
print(int(dp[N][3]%INF))
