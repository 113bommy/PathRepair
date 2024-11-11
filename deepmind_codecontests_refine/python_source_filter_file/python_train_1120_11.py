n,k=map(int,input().split())
lr=[list(map(int,input().split())) for _ in range(k)]

mod = 998244353

dp = [0] * (n+1)
sdp = [0] * (n+1)
dp[1] = 1
sdp[1] = 1

for i in range(n+1):
  for j in range(k):
    left = max(0, i-lr[j][1])
    right = max(0, i-lr[j][0]+1)
    
    dp[i] += sdp[right] - sdp[left]
  if i+1 <= n:
    sdp[i+1] = sdp[i]%mod + dp[i]%mod

print(dp%mod)