N,T = map(int,input().split())

item=[list(map(int,input().split())) for _ in range(N)]
item = sorted(item,key=lambda x:x[0])

dp=[[0]*(T+3000) for _ in range(N+1)]

for i,(a,b) in  enumerate(item,1):
    for t in reversed(range(T)):
        dist=t+a
        dp[i][dist] = max(dp[i-1][t]+b,dp[i][dist])
        dp[i][t]=max(dp[i-1][t],dp[i-1][t])
ans=0
for l in dp:
    ans=max(ans,max(l))
print(ans)
