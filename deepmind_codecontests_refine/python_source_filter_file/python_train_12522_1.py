x,y=map(int,input().split())
a=input()
b=input()
maxi=0
dp=[[0 for i in range(y+1)]for i in range(x+1)]
for i in range(1,x+1):
    for j in range(1,y+1):
        if a[i-1]==b[j-1]:
            dp[i][j]=dp[i-1][j-1]+2
        else:
            dp[i][j]=max(dp[i][j-1]-1,dp[i-1][j]-1)
        maxi=max(maxi,dp[i][j])
print(maxi)