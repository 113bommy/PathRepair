n,ma,mb=map(int,input().split())
dp=[[[10**30 for j in range(401)]for i in range(401)]for k in range(n+1)]
dp[0][0][0]=0 
l=[]
for i in range(n):
    a,b,c=map(int,input().split())
    l.append([a,b,c])
for i in range(1,n+1):
    a,b,c=l[i-1][0],l[i-1][1],l[i-1][2]
    for x in range(401):
        for y in range(401):
            if x<a or y<b:
                dp[i][x][y]=dp[i-1][x][y]
                continue 
            dp[i][x][y]=min(dp[i][x][y],dp[i-1][x-a][y-b]+c)
            
mini=10**30 
for i in range(1,40):
    mini=min(mini,dp[n][ma*i][mb*i])
if mini>=10**30 :
    print(-1)
else:
    print(mini)