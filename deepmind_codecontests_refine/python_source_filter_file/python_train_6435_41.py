K = list(map(int, list(input())))
D = int(input())
MOD = 10 ** 9 + 7

DP = [[[0] * 2 for _ in range(D)] for _ in range(len(K))]

for i in range(K[0]):
  DP[0][i % D][0] = 1
DP[0][K[0] % D][1] = 1

for i in range(1, len(K)):
  for j in range(10):
    for k in range(D):
      DP[i][(j + k) % D][0] = (DP[i][(j + k) % D][0] + DP[i - 1][k][0]) % MOD
  for j in range(K[i]):
    for k in range(D):
      DP[i][(j + k) % D][0] = (DP[i][(j + k) % D][0] + DP[i - 1][k][1]) % MOD
  for k in range(D):
    DP[i][(k + K[i]) % D][1] = (DP[i][(k + K[i]) % D][1] + DP[i - 1][k][1]) % MOD

ans = (DP[-1][0][0] + DP[-1][0][1] - 1) % MOD
while ans < 0:
  ans += MOD

print(ans)
