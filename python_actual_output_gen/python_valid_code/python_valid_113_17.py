n=int(input())
h=list(map(int,input().split()))
dp=[0]*n
dp[1]=abs(h[0]-h[1])
for i in range(n-2):
    dp[i+2]=min(dp[i+1]+abs(h[i+2]-h[i+1]),dp[i]+abs(h[i]-h[i+1]))
print(dp[n-1])