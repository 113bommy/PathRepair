h,n = map(int,input().split())

ls = [list(map(int,input().split())) for _ in range(n)]

amax = max(a for a,b in ls)

dp = [0]*(h+amax)

for i in range(1,h+amax):
  dp[i] = min(dp[max(0,i-a)]+b for a,b in ls)

print(min(dp[h:]))

