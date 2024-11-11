N, M = map(int, input().split())

inf = 10 ** 10

dp = [inf] * (1 << N)
dp[0] = 0
print(dp)


for _ in range(M):
    a, b = map(int, input().split())
    c = sum([2 ** (i - 1) for i in map(int, input().split())])
    #print(a, b)
    #print(c)

    for j in range(1 << N):
      dp[j | c] = min(dp[j] + a, dp[j | c])
      # print(j | c)
res = dp[-1] if dp[-1] != inf else -1
print(res)
