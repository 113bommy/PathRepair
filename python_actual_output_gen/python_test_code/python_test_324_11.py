n,m = (int(i) for i in input().split())
dp = [0]*(m+1)
ball = [1]*(m+1)
dp[0] = 1
for i in range(m):
  x,y = (int(i) for i in input().split())
  if dp[x-1] == 1:
    dp[y-1] = 1
  ball[x-1] -= 1
  ball[y-1] += 1
  if ball[x-1] == 0:
    dp[x-1] = 0
print(sum(dp))