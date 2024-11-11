def solve():
  n,l = map(int,input().split())
  
  length = [int(input()) for i in range(n)]
  pare = [(length[i], i) for i in range(n)]
  pare.sort(reverse=True)
  dp = [0] * (n + 1)
  for p in pare:
    i = p[0]
    if i == 0:
      dp[i] = dp[i + 1] + (l - length[i])
    else:
      dp[i] = max(dp[i - 1], dp[i + 1]) + (l - length[i])
  print(max(dp))
solve()
