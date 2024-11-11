H,N=map(int,input().split())
ab=[list(map(int,input().split())) for _ in range(N)]
x=max(a for a,b in ab)
dp=[0]*(H+10)
for i in range (1,H+1):
    dp[i]=min(dp[i-a]+b for a,b in ab)
print(dp[H])