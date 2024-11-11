n,t=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(n)]
AB.sort()
ma=AB[-1][0]
dp=[0]*(t+ma)    
for a,b in AB:
    for i in range(t+ma-1,a-1,-1):
        if i-a<t:
            dp[i]=max(dp[i],dp[i-a]+b)

print(max(dp))