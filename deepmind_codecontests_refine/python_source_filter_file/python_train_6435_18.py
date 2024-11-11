import sys
readline = sys.stdin.readline

# dp[i][smaller][d] : i桁目で、K未満で、そこまでの総和をDで割った余り = 個数

K = readline().rstrip()
D = int(readline())
DIV = 10 ** 9 + 7
keta = len(K)

dp = [[[0] * D for i in range(2)] for j in range(keta)]

x0 = int(K[0])
dp[0][0][x0 % D] = 1
bef = x0 % D # 未満じゃないときに直前に値が入っているmodを記録しておく
for i in range(x0):
  dp[0][1][i % D] += 1
  
for i in range(1, keta):
  x = int(K[i])
  
  # 未満じゃない -> 未満じゃない
  dp[i][0][(bef + x) % D] = 1
  
  # 未満じゃない -> 未満
  # 0~x-1の値を取り得る
  for j in range(x):
    dp[i][1][(bef + j) % D] += dp[i - 1][0][bef]
  
  for j in range(D):
    dp[i][1][j] %= DIV
  
  bef = (bef + x) % D # 未満じゃないときに値が入っているmodを記録
  
  # 未満 -> 未満
  for j in range(D):
    for k in range(10): # 0~9のすべてを取れる
      dp[i][1][(k + j) % D] += dp[i - 1][1][j]
      
  for j in range(D):
    dp[i][1][j] %= DIV

print((dp[-1][0][0] + dp[-1][1][0]) % DIV - 1) # 0を数えないので引く