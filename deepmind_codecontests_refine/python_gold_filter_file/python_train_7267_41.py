from collections import Counter
n = int(input())
a = list(map(int,input().split()))
c = Counter(a)
c1,c2,c3 = c[1],c[2],c[3]
dp = [[[0 for i in range(c3+1)] for j in range(c2+c3+1)] for k in range(c1+c2+c3+1)]
#dp[i][j][k] := 1個×i皿、2個×j皿、3個×k皿における期待値
for k in range(c3+1):
  for j in range(c2+c3+1):
    for i in range(n+1):
      if i+j+k > n or i == j == k == 0:
        continue
      x = (n-i-j-k)/n
      dp[i][j][k] = 1
      if 0<i :
        dp[i][j][k] += dp[i-1][j][k]*(i/n)
      if 0<j and i+1<=n:
        dp[i][j][k] += dp[i+1][j-1][k]*(j/n)
      if 0<k and j+1<=c2+c3:
        dp[i][j][k] += dp[i][j+1][k-1]*(k/n)
      dp[i][j][k] /= 1-x
print(dp[c1][c2][c3])
