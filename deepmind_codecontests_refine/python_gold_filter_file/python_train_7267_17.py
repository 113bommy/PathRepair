n = int(input())
a = list(map(int, input().split()))
uno = a.count(1)
dos = a.count(2)
tres = n - uno - dos
dp = [[[.0]*(n+1) for _ in range(dos+tres+1)] for j in range(tres+1)]
for k in range(tres+1):
  for j in range(dos+tres-k+1):
    for i in range(n+1-j-k):
      if i+j+k == 0: continue
      v = i+j+k
      res = n
      if i: res += i * dp[k][j][i-1]
      if j: res += j * dp[k][j-1][i+1]
      if k: res += k * dp[k-1][j+1][i]
      dp[k][j][i] = res / v
print(dp[tres][dos][uno]) 
