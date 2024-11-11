N = int(input())

DP = [[0 for _ in range(10)] for _ in range(10)]

for i in range(1, N):
  DP[int(str(i)[0])][int(str(i)[-1])] += 1

ans = 0
for i in range(10):
  for j in range(10):
    ans += DP[i][j] * DP[j][i]

print(ans)