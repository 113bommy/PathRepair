X=input()
Y=input()
dp=[[0 for y in range(1+len(Y))] for x in range(1+len(X))]
for x in range(len(X)):
    dp[x+1][0]=x+1
    for y in range(len(Y)):
        dp[0][y+1]=y+1
        if X[x]==Y[y]:cost=0
        elif X[x]!=Y[y]:cost=1
        dp[1+x][1+y]=min(dp[x][1+y]+1,dp[x][1+y]+1,dp[x][y]+cost)
print(dp[len(X)][len(Y)])
