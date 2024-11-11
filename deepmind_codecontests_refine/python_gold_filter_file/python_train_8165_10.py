n=int(input())
a=list(map(int,input().split()))

ma=max(a)
dp=[0]*(ma+4)

for i in a:
    dp[i]+=i

for i in range(ma,0,-1):
    dp[i]=dp[i]+max(dp[i+2],dp[i+3])

print(max(dp[1],dp[2]))