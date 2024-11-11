H,W=map(int,input().split())
A=[[int(i) for i in input().split()] for j in range(H)]
B=[[int(i) for i in input().split()] for j in range(H)]
dp=[[0 for j in range(W)] for i in range(H)]
M=161*161
dp[0][0]|=1<<(A[0][0]-B[0][0]+M)
dp[0][0]|=1<<(-A[0][0]+B[0][0]+M)

for i in range(H):
    for j in range(W):
        dij=abs(A[i][j]-B[i][j])
        if i>0:
            dp[i][j]|=dp[i-1][j]<<dij
            dp[i][j]|=dp[i-1][j]>>dij
        if j>0:
            dp[i][j]|=dp[i][j-1]>>dij
            dp[i][j]|=dp[i][j-1]<<dij
ans=[]
for i in range(M):
    if (1<<i)&dp[-1][-1]!=0:
        ans.append(abs(i-M))
print(min(ans))
